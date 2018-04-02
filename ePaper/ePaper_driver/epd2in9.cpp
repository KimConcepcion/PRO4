
#include "epd2in9.h"
#include "SPI.h"
#include <fstream>

Epd::~Epd() {
};

Epd::Epd() {
    width = EPD_WIDTH;
    height = EPD_HEIGHT;
    lut = NULL;
};

int Epd::Init(const unsigned char* lut) {
    /* this calls the peripheral hardware interface, see epdif */
    if (IfInit() != 0) {
        return -1;
    }
    /* EPD hardware init start */
    this->lut = lut;
    Reset();
    transferCommand((unsigned char *) DRIVER_OUTPUT_CONTROL);
    transferData( (unsigned char *) ((EPD_HEIGHT - 1) & 0xFF));
    transferData((unsigned char *) (((EPD_HEIGHT - 1) >> 8) & 0xFF));
    transferData(0x00);                     // GD = 0; SM = 0; TB = 0;
    transferCommand((unsigned char *) BOOSTER_SOFT_START_CONTROL);
    transferData((unsigned char *) 0xD7);
    transferData((unsigned char *) 0xD6);
    transferData((unsigned char *) 0x9D);
    transferCommand((unsigned char *) WRITE_VCOM_REGISTER);
    transferData((unsigned char *) 0xA8);                     // VCOM 7C
    transferCommand((unsigned char *) SET_DUMMY_LINE_PERIOD);
    transferData((unsigned char *) 0x1A);                     // 4 dummy lines per gate
    transferCommand((unsigned char *) SET_GATE_TIME);
    transferData((unsigned char *) 0x08);                     // 2us per line
    transferCommand((unsigned char *) DATA_ENTRY_MODE_SETTING);
    transferData((unsigned char *) 0x03);                     // X increment; Y increment
    SetLut(this->lut);
    /* EPD hardware init end */
    return 0;
}

/**
 *  @brief: Wait until the busy_pin goes LOW
 */
void Epd::WaitUntilIdle(void) {

	int status;
	ifstream r_file (BUSY);
	r_file >> status;
	Epd obj;

	while(status == 1)
	{
		obj.DelayMs(100);
		r_file >> status;	//	Get new status from RST pin
	}

    r_file.close();
}

/**
 *  @brief: module reset.
 *          often used to awaken the module in deep sleep,
 *          see Epd::Sleep();
 */
void Epd::Reset(void) {

	Epd obj;

	ofstream w_file (RST);
	w_file << 0;
	obj.DelayMs(200);
	w_file << 1;
	obj.DelayMs(200);
}

/**
 *  @brief: set the look-up table register
 */
void Epd::SetLut(const unsigned char* lut) {
    this->lut = lut;
    transferCommand((unsigned char *) WRITE_LUT_REGISTER);
    /* the length of look-up table is 30 bytes */
    for (int i = 0; i < 30; i++) {
        transferData((unsigned char *) this->lut[i]);
    }
}

/**
 *  @brief: put an image buffer to the frame memory.
 *          this won't update the display.
 */
void Epd::SetFrameMemory(
    const unsigned char* image_buffer,
    int x,
    int y,
    int image_width,
    int image_height
) {
    int x_end;
    int y_end;

    if (
        image_buffer == NULL ||
        x < 0 || image_width < 0 ||
        y < 0 || image_height < 0
    ) {
        return;
    }
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    x &= 0xF8;
    image_width &= 0xF8;
    if (x + image_width >= this->width) {
        x_end = this->width - 1;
    } else {
        x_end = x + image_width - 1;
    }
    if (y + image_height >= this->height) {
        y_end = this->height - 1;
    } else {
        y_end = y + image_height - 1;
    }
    SetMemoryArea(x, y, x_end, y_end);
    SetMemoryPointer(x, y);
    transferCommand((unsigned char *) WRITE_RAM);
    /* send the image data */
    for (int j = 0; j < y_end - y + 1; j++) {
        for (int i = 0; i < (x_end - x + 1) / 8; i++) {
            transferData((unsigned char *) (image_buffer[i + j * (image_width / 8)]));
        }
    }
}

/**
 *  @brief: put an image buffer to the frame memory.
 *          this won't update the display.
 *
 *          Question: When do you use this function instead of
 *          void SetFrameMemory(
 *              const unsigned char* image_buffer,
 *              int x,
 *              int y,
 *              int image_width,
 *              int image_height
 *          );
 *          Answer: SetFrameMemory with parameters only reads image data
 *          from the RAM but not from the flash in AVR chips (for AVR chips,
 *          you have to use the function pgm_read_byte to read buffers
 *          from the flash).
 */
void Epd::SetFrameMemory(const unsigned char* image_buffer) {
    SetMemoryArea(0, 0, this->width - 1, this->height - 1);
    SetMemoryPointer(0, 0);
    transferCommand((unsigned char *) WRITE_RAM);

    /* send the image data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        transferData( (unsigned char *) (pgm_read_byte(&image_buffer[i])) );
    }
}

/**
 *  @brief: clear the frame memory with the specified color.
 *          this won't update the display.
 */
void Epd::ClearFrameMemory(unsigned char color) {
    SetMemoryArea(0, 0, this->width - 1, this->height - 1);
    SetMemoryPointer(0, 0);
    transferCommand((unsigned char *) WRITE_RAM);
    /* send the color data */
    for (int i = 0; i < this->width / 8 * this->height; i++) {
        transferData(&color);
    }
}

/**
 *  @brief: update the display
 *          there are 2 memory areas embedded in the e-paper display
 *          but once this function is called,
 *          the the next action of SetFrameMemory or ClearFrame will
 *          set the other memory area.
 */
void Epd::DisplayFrame(void) {
    transferCommand((unsigned char *) DISPLAY_UPDATE_CONTROL_2);
    transferData((unsigned char *) 0xC4);
    transferCommand((unsigned char *) MASTER_ACTIVATION);
    transferCommand((unsigned char *) TERMINATE_FRAME_READ_WRITE);
    WaitUntilIdle();
}

/**
 *  @brief: private function to specify the memory area for data R/W
 */
void Epd::SetMemoryArea(int x_start, int y_start, int x_end, int y_end) {
    transferCommand((unsigned char *) SET_RAM_X_ADDRESS_START_END_POSITION);
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    transferData((unsigned char *) ((x_start >> 3) & 0xFF));
    transferData((unsigned char *) ((x_end >> 3) & 0xFF));
    transferCommand((unsigned char *) SET_RAM_Y_ADDRESS_START_END_POSITION);
    transferData((unsigned char *) (y_start & 0xFF));
    transferData((unsigned char *) (y_start >> 8) & 0xFF);
    transferData((unsigned char *) (y_end & 0xFF));
    transferData((unsigned char *) ((y_end >> 8) & 0xFF));
}

/**
 *  @brief: private function to specify the start point for data R/W
 */
void Epd::SetMemoryPointer(int x, int y) {
    transferCommand((unsigned char *) SET_RAM_X_ADDRESS_COUNTER);
    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
    transferData((unsigned char *) ((x >> 3) & 0xFF));
    transferCommand((unsigned char *) SET_RAM_Y_ADDRESS_COUNTER);
    transferData((unsigned char *) (y & 0xFF));
    transferData((unsigned char *) ((y >> 8) & 0xFF));
    WaitUntilIdle();
}

/**
 *  @brief: After this command is transmitted, the chip would enter the
 *          deep-sleep mode to save power.
 *          The deep sleep mode would return to standby by hardware reset.
 *          You can use Epd::Init() to awaken
 */
void Epd::Sleep() {
    transferCommand((unsigned char *) DEEP_SLEEP_MODE);
    WaitUntilIdle();
}

const unsigned char lut_full_update[] =
{
    0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22,
    0x66, 0x69, 0x69, 0x59, 0x58, 0x99, 0x99, 0x88,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0xB4, 0x13, 0x51,
    0x35, 0x51, 0x51, 0x19, 0x01, 0x00
};

const unsigned char lut_partial_update[] =
{
    0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x44, 0x12,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void Epd::transferCommand(unsigned char *command)
{
	SPI SPI;
	int fd = 0;
	unsigned char null = 0x00;

	ofstream w_file (DC);
	w_file << 0;
	w_file.close();

	SPI.spi_transfer(fd, command, &null, 1);
}

void Epd::transferData(unsigned char *data)
{
	SPI SPI;
	int fd = 0;
	unsigned char null = 0x00;

	ofstream w_file (DC);
	w_file << 1;
	w_file.close();

	SPI.spi_transfer(fd, data, &null, 1);
}
