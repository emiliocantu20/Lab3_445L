// Timer.c
// Runs on LM4F120/TM4C123
// Provide functions that generates a timer.
// Use bit-banded I/O.
// Emilio Cantu, Manolo Alvarez and John Valvano
// Sep 16, 2020

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/CortexM.h" 
#include "../inc/tm4c123gh6pm.h"
#include "../inc/PLL.h"
#include "Switches.h"

//initialize port C 4-7

//------------SwitchPC4567_Init------------
// Initialize GPIO Port A bit 5 for input
// Input: none
// Output: none
void SwitchPC4567_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x04;//0x00000100;     // 1) activate clock for Port C
  while((SYSCTL_PRGPIO_R&0x04) == 0){};// ready?
  GPIO_PORTC_AMSEL_R &= ~0xF0;      // 3) disable analog on PC4-7
  GPIO_PORTC_PCTL_R &= ~0xFFFF0000; // 4) PCTL GPIO on PC4-7
  GPIO_PORTC_DIR_R &= ~0xF0;        // 5) direction PC4-7 input
  GPIO_PORTC_AFSEL_R &= ~0xF0;      // 6) PC4-7 regular port function
  GPIO_PORTC_DEN_R |= 0xF0;         // 7) enable PC4-7 digital port
}
//------------SwitchPC4_Input------------
// Read and return the status of GPIO Port C bit 4 
// Input: none
// Output: 0x10 if PC4 is high
//         0x00 if PC4 is low
uint32_t SwitchPC4_Input(void){
  return PC4; // return 0x10(pressed) or 0(not pressed)
}
uint32_t SwitchPC4_Input2(void){
  return (GPIO_PORTA_DATA_R&0x10); // 0x10(pressed) or 0(not pressed)
}
//------------SwitchPC4_WaitForTouch------------
// wait for the switch to be touched 
// Input: none
// Output: none
// debounces switch
void SwitchPC4_WaitForTouch(void){
// wait for release
  while(SwitchPC4_Input()){};
  //Clock_Delay1ms(10); // 10ms
// wait for touch
  while(SwitchPC4_Input()==0){};
  //Clock_Delay1ms(10); // 10ms
}

//------------SwitchPC5_Input------------
// Read and return the status of GPIO Port C bit 5 
// Input: none
// Output: 0x20 if PC5 is high
//         0x00 if PC5 is low
uint32_t SwitchPC5_Input(void){
  return PC5; // return 0x20(pressed) or 0(not pressed)
}
uint32_t SwitchPC5_Input2(void){
  return (GPIO_PORTA_DATA_R&0x20); // 0x20(pressed) or 0(not pressed)
}
//------------SwitchPC5_WaitForTouch------------
// wait for the switch to be touched 
// Input: none
// Output: none
// debounces switch
void SwitchPC5_WaitForTouch(void){
// wait for release
  while(SwitchPC5_Input()){};
  //Clock_Delay1ms(10); // 10ms
// wait for touch
  while(SwitchPC5_Input()==0){};
  //Clock_Delay1ms(10); // 10ms
}
//------------SwitchPC6_Input------------
// Read and return the status of GPIO Port C bit 6 
// Input: none
// Output: 0x40 if PC6 is high
//         0x00 if PC6 is low

uint32_t SwitchPC6_Input(void){
  return PC6; // return 0x40(pressed) or 0(not pressed)
}
uint32_t SwitchPC6_Input2(void){
  return (GPIO_PORTA_DATA_R&0x40); // 0x40(pressed) or 0(not pressed)
}
//------------SwitchPC6_WaitForTouch------------
// wait for the switch to be touched 
// Input: none
// Output: none
// debounces switch
void SwitchPC6_WaitForTouch(void){
// wait for release
  while(SwitchPC6_Input()){};
  //Clock_Delay1ms(10); // 10ms
// wait for touch
  while(SwitchPC6_Input()==0){};
  //Clock_Delay1ms(10); // 10ms
}

//------------SwitchPC7_Input------------
// Read and return the status of GPIO Port C bit 7 
// Input: none
// Output: 0x80 if PC7 is high
//         0x00 if PC7 is low

uint32_t SwitchPC7_Input(void){
  return PC7; // return 0x80(pressed) or 0(not pressed)
}
uint32_t SwitchPC7_Input2(void){
  return (GPIO_PORTA_DATA_R&0x80); // 0x80(pressed) or 0(not pressed)
}
//------------SwitchPC7_WaitForTouch------------
// wait for the switch to be touched 
// Input: none
// Output: none
// debounces switch
void SwitchPC7_WaitForTouch(void){
// wait for release
  while(SwitchPC7_Input()){};
  //Clock_Delay1ms(10); // 10ms
// wait for touch
  while(SwitchPC7_Input()==0){};
  //Clock_Delay1ms(10); // 10ms
}
/*
//------------SwitchPA5_Debounce------------
// Read and return the status of the switch 
// Input: none
// Output: 0x20 if PA5 is high
//         0x00 if PA5 is low
// debounces switch
uint32_t SwitchPA5_Debounce(void){
uint32_t in,old,time; 
  time = 1000; // 10 ms
  old = SwitchPA5_Input();
  while(time){
    Clock_Delay(237); // 10us
    in = SwitchPA5_Input();
    if(in == old){
      time--; // same value for 10ms
    }else{
      time = 1000;  // different
      old = in;
    }
  }
  return old;
}
*/

