
#ifndef MAIL_H_
#define MAIL_H_

#define MSG_FILE "mail.txt"
#define COMMAND "cat mail.txt | sendmail -t"

//	Stages:
#define T_HIGH "For høj temperatur!"
#define T_LOW "For lav temperatur!"
#define M_HIGH "Dine planter drukner i vand!"
#define M_LOW "Dine planter mangler vand!"
#define L_HIGH "For høj lysstyrke!"
#define L_LOW "For lav lysstyrke!"

int sendMail(const char *message);

#endif
