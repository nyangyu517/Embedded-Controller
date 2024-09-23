/*----------------------------------------------------------------\
@ Embedded Controller by Hyeon-Gyu Jeon - Handong Global University
Author           : HGU
Created          : 09-10-2024
Modified         : 09-23-2024
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/


#ifndef __ECGPIO2_H
#define __ECGPIO2_H

#include "stm32f411xe.h"
#include "ecRCC2.h"
#include "ecPinNames.h"


typedef enum{INPUT = 0, OUTPUT, Alternate_Function, ANALOG}GPIO_MODE;
typedef enum{PUSH_PULL = 0, OPEN_DRAIN =1}GPIO_TYPE;
typedef enum{LOW_SPEED = 0b00, 
						MEDIUM_SPEED = 0b01, 
						FAST_SPEED = 0b10, 
						HIGH_SPEED = 0b11}GPIO_SPEED;
typedef enum{NO_PUPD = 0, PU, PD}GPIO_PUPD;


#define HIGH 1
#define LOW  0

#define LED_PIN1 PA_7    //Find LED Port&Pin and Fill the blank
#define LED_PIN2 PB_6
#define LED_PIN3 PC_7
#define LED_PIN4 PA_9

#define BUTTON_PIN PC_13 //Find BTN Port&Pin and Fill the blank

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
	 
void GPIO_init(PinName_t pinName, uint32_t mode);     
void GPIO_write(PinName_t pinName, int Output);
int  GPIO_read(PinName_t pinName);
void GPIO_mode(PinName_t pinName, uint32_t mode);
void GPIO_ospeed(PinName_t pinName, int speed);
void GPIO_otype(PinName_t pinName, int type);
void GPIO_pupd(PinName_t pinName, int pupd);

/*----------7segment-----------*/
void sevensegment_display_init(PinName_t pinNameA, PinName_t pinNameB, PinName_t pinNameC, PinName_t pinNameD); 
void sevensegment_display(uint8_t num);

void storePinName(PinName_t pinNamea, PinName_t pinNameb, PinName_t pinNamec, PinName_t pinNamed, PinName_t pinNamee, PinName_t pinNamef, PinName_t pinNameg, PinName_t pinNameh);

void sevensegment_decoder_init(void); 
void sevensegment_decoder(uint8_t num);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __ECGPIO2_H
