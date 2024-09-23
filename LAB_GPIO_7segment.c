/*----------------------------------------------------------------\
@ Embedded Controller by Hyeon-Gyu Jeon - Handong Global University
Author           : HGU
Created          : 09-10-2024
Modified         : 09-23-2024
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/

#include "stm32f4xx.h"
#include "ecGPIO2_student.h"
#include "ecRCC2.h"

#define segment_PIN1 PA_5    //Find LED Port&Pin and Fill the blank
#define segment_PIN2 PA_6
#define segment_PIN3 PA_7
#define segment_PIN4 PB_6
#define segment_PIN5 PC_7
#define segment_PIN6 PA_9
#define segment_PIN7 PA_8
#define segment_PIN8 PB_10

#define BUTTON_PIN PC_13

void setup(void);
void sevensegment_decoder_init(void);
void sevensegment_decoder(uint8_t num);


int main(void) { 
	// Initialiization --------------------------------------------------------
	
	setup();
	unsigned int cnt = 0;
	sevensegment_decoder_init();

	// Inifinite Loop ----------------------------------------------------------
	
	while(1){
		sevensegment_decoder(cnt % 10);
		if(GPIO_read(BUTTON_PIN) == 0) cnt++; 
        if (cnt > 9) cnt = 0;
		for(int i = 0; i < 500000;i++){}  // delay_ms(500);
	}
}

// Initialiization 
void setup(void)
{
	RCC_HSI_init();	

	GPIO_init(BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_pupd(BUTTON_PIN, PU);		 // set button pin PULL-UP
		
	GPIO_otype(segment_PIN1, 0);	 // set segment pin 1~8 to PUSH-PULL
	GPIO_otype(segment_PIN2, 0);
	GPIO_otype(segment_PIN3, 0);
	GPIO_otype(segment_PIN4, 0);
	GPIO_otype(segment_PIN5, 0);
	GPIO_otype(segment_PIN6, 0);
	GPIO_otype(segment_PIN7, 0);
	GPIO_otype(segment_PIN8, 0);
	
	GPIO_pupd(segment_PIN1, 0);	 	 // set segment pin 1~8 to NO PUPD
	GPIO_pupd(segment_PIN2, 0);
	GPIO_pupd(segment_PIN3, 0);
	GPIO_pupd(segment_PIN4, 0);
	GPIO_pupd(segment_PIN5, 0);
	GPIO_pupd(segment_PIN6, 0);
	GPIO_pupd(segment_PIN7, 0);
	GPIO_pupd(segment_PIN8, 0);
	
	GPIO_ospeed(segment_PIN1, 01);	 // set segment pin 1~8 to Medium speed
	GPIO_ospeed(segment_PIN2, 01);
	GPIO_ospeed(segment_PIN3, 01);
	GPIO_ospeed(segment_PIN4, 01);
	GPIO_ospeed(segment_PIN5, 01);
	GPIO_ospeed(segment_PIN6, 01);
	GPIO_ospeed(segment_PIN7, 01);
	GPIO_ospeed(segment_PIN8, 01);
	
	storePinName(segment_PIN1, segment_PIN2, segment_PIN3, segment_PIN4,
							 segment_PIN5, segment_PIN6, segment_PIN7, segment_PIN8); // Store segment pin 1~8 to pinNameA~H
}


