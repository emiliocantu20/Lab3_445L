// Sound.h
// Runs on LM4F120/TM4C123
// Low level drivers for the ST7735 160x128 LCD based off of
// the file described above.
//    16-bit color, 128 wide by 160 high LCD
// Emilio Cantu and Manolo Alvarez, September 16, 2020
// Augmented 7/17/2014 to have a simple graphics facility
// Tested with LaunchPadDLL.dll simulator 9/2/2014

#ifndef _SoundH_
#define _SoundH_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/tm4c123gh6pm.h"

//------------SwitchD1_Init------------
// Initialize GPIO Port D bit 1 for input
// Input: none
// Output: none
void SwitchPD1_Init(void);

//------------SwitchPD1_Input------------
// Read and return the status of GPIO Port D bit 1 
// Input: none
// Output: 0x02 if PD1 is high
//         0x00 if PD1 is low
uint32_t SwitchPD1_getOutput(void);






























#endif
