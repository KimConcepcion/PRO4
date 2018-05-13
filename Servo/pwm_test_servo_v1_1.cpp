/*
 * pwm_test_servo_v1_0.cpp amended on: May 2018
 * pwm_test.cpp  Created on: 3rd Feb 2015
 * Copyright (c) 2014 Derek Molloy (www.derekmolloy.ie)
 * Made available for the book "Exploring BeagleBone"
 * See: www.exploringbeaglebone.com
 * Licensed under the EUPL V.1.1
 *
 * This Software is provided to You under the terms of the European
 * Union Public License (the "EUPL") version 1.1 as published by the
 * European Union. Any use of this Software, other than as authorized
 * under this License is strictly prohibited (to the extent such use
 * is covered by a right of the copyright holder of this Software).
 *
 * This Software is provided under the License on an "AS IS" basis and
 * without warranties of any kind concerning the Software, including
 * without limitation merchantability, fitness for a particular purpose,
 * absence of defects or errors, accuracy, and non-infringement of
 * intellectual property rights other than copyright. This disclaimer
 * of warranty is an essential part of the License and a condition for
 * the grant of any rights to this Software.
 *
 * For more details, see http://www.derekmolloy.ie/
 *
 * Amended by Jesper Hjort in May 2018
 */

#include<iostream>    // std::cout, std::endl
#include"PWM.h"       // placed in the current directory for ease of use
#include <thread>     // std::this_thread::sleep_for
#include <chrono>     // std::chrono::seconds

using namespace exploringBB;
using namespace std;

int main(){
    // PWM P9_14 and P9_16 MUST be loaded as slots before use
	// PWM pwm("pwm_test_P9_16.17");  // pwm signal on BBB pin 9_16 to control lock mechanism servos
   PWM pwm("pwm_test_P9_14.16");  // pwm signal on BBB pin 9_14 to control down/up lifting servos
   pwm.setPeriod(20000000);         // Set the period in ns
   pwm.setDutyCycle(570000u);       // Set the duty cycle in nano seconds 570000 ns = -90 degrees
   pwm.setPolarity(PWM::ACTIVE_HIGH);  // using active high PWM = 0
   pwm.run(); // start the PWM output
   std::this_thread::sleep_for (std::chrono::seconds(2)); // sleep for 2 seconds
   pwm.setDutyCycle(2350000u);       // Set the duty cycle in nano seconds 2350000 ns = +90 degrees
   std::this_thread::sleep_for (std::chrono::seconds(5)); // sleep for 5 seconds
   pwm.setDutyCycle(570000u);       // Set the duty cycle in nano seconds 570000 ns = -90 degrees
   std::this_thread::sleep_for (std::chrono::seconds(2)); // sleep for 5 seconds
   pwm.stop(); // stop the PWM output aka avoid torque on servo when idle

}
