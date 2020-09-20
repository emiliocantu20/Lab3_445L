// Sound.c
// Runs on LM4F120/TM4C123
// Provide functions that generates sound from Port D1.
// Use bit-banded I/O.
// Emilio Cantu, Manolo Alvarez and John Valvano
// Sep 16, 2020

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/tm4c123gh6pm.h"
#include "Sound.h"
//------------SwitchD1_Init------------
// Initialize GPIO Port D bit 1 for input
// Input: none
// Output: none
void SwitchPD1_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x00000008;     // 1) activate clock for Port D
  while((SYSCTL_PRGPIO_R&0x08) == 0){};// ready?
  GPIO_PORTD_AMSEL_R &= ~0x02;      // 3) disable analog on PD1
  GPIO_PORTD_PCTL_R &= ~0x000000F0; // 4) PCTL GPIO on PD1
  GPIO_PORTD_DIR_R |= 0x02;        // 5) direction PD1 input
  GPIO_PORTD_AFSEL_R &= ~0x02;      // 6) D1 regular port function
  GPIO_PORTD_DEN_R |= 0x02;         // 7) enable D1 digital port
}

//------------SwitchPD1_Input------------
// Read and return the status of GPIO Port D bit 1 
// Input: none
// Output: 0x02 if PD1 is high
//         0x00 if PD1 is low
uint32_t SwitchPD1_getOutput(void){
  return (GPIO_PORTD_DATA_R&0x02); // 0x02(pressed) or 0(not pressed)
}
