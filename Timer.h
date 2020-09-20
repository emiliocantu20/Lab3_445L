// Timer.h
// Runs on LM4F120/TM4C123
// Low level drivers for the ST7735 160x128 LCD based off of
// the file described above.
//    16-bit color, 128 wide by 160 high LCD
// Emilio Cantu and Manolo Alvarez, September 16, 2020
// Augmented 7/17/2014 to have a simple graphics facility
// Tested with LaunchPadDLL.dll simulator 9/2/2014

#ifndef _TimerH_
#define _TimerH_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/tm4c123gh6pm.h"

void SysTick_Init(uint32_t period);




#endif
