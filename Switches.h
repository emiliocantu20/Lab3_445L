// Switches.h
// Runs on LM4F120/TM4C123
// Low level drivers for the ST7735 160x128 LCD based off of
// the file described above.
//    16-bit color, 128 wide by 160 high LCD
// Emilio Cantu and Manolo Alvarez, September 16, 2020
// Augmented 7/17/2014 to have a simple graphics facility
// Tested with LaunchPadDLL.dll simulator 9/2/2014

#ifndef _SwitchesH_
#define _SwitchesH_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/CortexM.h" 
#include "../inc/tm4c123gh6pm.h"
#define PC4  (*((volatile uint32_t *)0x4005A040))
#define PC5  (*((volatile uint32_t *)0x4005A080))
#define PC6  (*((volatile uint32_t *)0x4005A100))
#define PC7  (*((volatile uint32_t *)0x4005A200))

//Initializes Port C Pins C4-7
void SwitchPC4567_Init(void);

//Port C4 Input
uint32_t SwitchPC4_Input(void);
uint32_t SwitchPC4_Input2(void);
void SwitchPC4_WaitForTouch(void);
//Port C5 Input
uint32_t SwitchPC5_Input(void);
uint32_t SwitchPC5_Input2(void);
void SwitchPC5_WaitForTouch(void);
//Port C6 Input
uint32_t SwitchPC6_Input(void);
uint32_t SwitchPC6_Input2(void);
void SwitchPC6_WaitForTouch(void);
//Port C7 Input
uint32_t SwitchPC7_Input(void);
uint32_t SwitchPC7_Input2(void);
void SwitchPC7_WaitForTouch(void);


#endif
