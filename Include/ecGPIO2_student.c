/*----------------------------------------------------------------\
@ Embedded Controller by Hyeon-Gyu Jeon - Handong Global University
Author           : HGU
Created          : 09-10-2024
Modified         : 09-23-2024
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/



#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO2_student.h"

void GPIO_init(PinName_t pinName, uint32_t mode){     
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	
	// mode  : Input(0), Output(1), AlterFunc(2), Analog(3)   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	
	if (Port == GPIOB)
		RCC_GPIOB_enable();
	
	if (Port == GPIOC)
		RCC_GPIOC_enable();
	
	if (Port == GPIOD)
		RCC_GPIOD_enable();
	
	if (Port == GPIOE)
		RCC_GPIOE_enable();
	
	if (Port == GPIOH)
		RCC_GPIOH_enable();



	
	//[TO-DO] YOUR CODE GOES HERE
	// Make it for GPIOB, GPIOD..GPIOH

	// You can also make a more general function of
	// void RCC_GPIO_enable(GPIO_TypeDef *Port); 

	GPIO_mode(pinName, mode);
}


// GPIO Mode: Input(00), Output(01), AlterFunc(10), Analog(11)
void GPIO_mode(PinName_t pinName, uint32_t mode){
   GPIO_TypeDef * Port;
   unsigned int pin;
   ecPinmap(pinName,&Port,&pin);
   Port->MODER &= ~(3UL<<(2*pin));     
   Port->MODER |= (mode<<(2*pin));  
}  


// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
void GPIO_ospeed(PinName_t pinName, int speed){
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port->OSPEEDR &= ~(3UL << (2 * pin));
	Port->OSPEEDR |= speed << (2 * pin);
}

// GPIO Output Type: Output push-pull (0, reset), Output open drain (1)
void GPIO_otype(PinName_t pinName, int type){
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port->OTYPER &= ~(1<<(pin));
	Port->OTYPER |= type << (pin);
}

// GPIO Push-Pull    : No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
void GPIO_pupd(PinName_t pinName, int pupd){
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port->PUPDR &= ~(3UL << (2 * pin));
	Port->PUPDR |= pupd << (2 * pin);
}

// GPIO read
int GPIO_read(PinName_t pinName){
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	
	return (Port->IDR>>pin)&1;
}

//GPIO write
void GPIO_write(PinName_t pinName, int Output){
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port-> ODR &= ~(1UL<<(pin));
	Port-> ODR |= (Output<<pin);
}

// Declare pinNameA~H
PinName_t pinNameA;		
PinName_t pinNameB; 
PinName_t pinNameC; 
PinName_t pinNameD;
PinName_t pinNameE;
PinName_t pinNameF;
PinName_t pinNameG;
PinName_t pinNameH;

// Setup the PinNameA~D to OUTPUT for display 7segment
void sevensegment_display_init(PinName_t pinNameA, PinName_t pinNameB, PinName_t pinNameC, PinName_t pinNameD){
		GPIO_init(pinNameA,OUTPUT);
		GPIO_init(pinNameB,OUTPUT);
		GPIO_init(pinNameC,OUTPUT);
		GPIO_init(pinNameD,OUTPUT);
}																 


// Using 7segment decoder, the setting of decoder INPUT for number 0~9
void sevensegment_display(uint8_t num){
		
		if (num == 0){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		}
		
		if (num == 1){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		}
		
		if (num == 2){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		}
		
		if (num == 3){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		}
		
		if (num == 4){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		}
		
		if (num == 5){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		}
		
		if (num == 6){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		}
		
		if (num == 7){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		}
		
		if (num == 8){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,1);
		GPIO_write(pinNameD,0);
		}
		
		if (num == 9){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,1);
		GPIO_write(pinNameD,1);
		}
		
	}


// Setup the pinNamea~h to pinNameA~H to use this place	
void storePinName(PinName_t pinNamea, PinName_t pinNameb, PinName_t pinNamec, PinName_t pinNamed, PinName_t pinNamee, PinName_t pinNamef, PinName_t pinNameg, PinName_t pinNameh){
	pinNameA = pinNamea;
	pinNameB = pinNameb;
	pinNameC = pinNamec;
	pinNameD = pinNamed;
	pinNameE = pinNamee;
	pinNameF = pinNamef;
	pinNameG = pinNameg;
	pinNameH = pinNameh;
}


// Setup the PinNameA~H to OUTPUT for display 7segment
void sevensegment_decoder_init(void){
		GPIO_init(pinNameA,OUTPUT);
		GPIO_init(pinNameB,OUTPUT);
		GPIO_init(pinNameC,OUTPUT);
		GPIO_init(pinNameD,OUTPUT);
		GPIO_init(pinNameE,OUTPUT);
		GPIO_init(pinNameF,OUTPUT);
		GPIO_init(pinNameG,OUTPUT);
		GPIO_init(pinNameH,OUTPUT);
}


// Not using 7segment decoder, the setting of 7segment INPUT for number 0~9
void sevensegment_decoder(uint8_t num){
	
		if (num == 0){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,0);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,1);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 1){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,1);
		GPIO_write(pinNameG,1);
		GPIO_write(pinNameH,1);
		}
		
		if (num == 2){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,1);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,0);
		GPIO_write(pinNameF,1);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 3){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,1);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 4){
		GPIO_write(pinNameA,1);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 5){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 6){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,1);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,0);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 7){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,1);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,1);
		GPIO_write(pinNameG,1);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 8){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,0);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
		if (num == 9){
		GPIO_write(pinNameA,0);
		GPIO_write(pinNameB,0);
		GPIO_write(pinNameC,0);
		GPIO_write(pinNameD,0);
		GPIO_write(pinNameE,1);
		GPIO_write(pinNameF,0);
		GPIO_write(pinNameG,0);
		GPIO_write(pinNameH,0);
		}
		
}

























