/*
 * hGPIO_LIB.c
 *
 *  Created on: Dec 3, 2017
 *      Author: Chris
 */

#include "hGPIO_LIB.h"
// **************************** GPIO FUNCTIONS ********************************

/* To convert from GPIO_PIN to GPIO_PIN_Source */
uint8_t PinToAFSource(uint16_t PIN)
{
	uint8_t PinSource = 0;
	while(PIN != 0)
	{
		PIN >>= 1;
		PinSource++;
	}
	return (PinSource-1);
}

void AnalogIn(GPIO_TypeDef* PORT, uint16_t PIN)
{
	GPIO_InitTypeDef GPIOInitStruct;

	GPIO_StructInit(&GPIOInitStruct); // Default values - Input, PP, NoPull, VeryLow Speed
	GPIOInitStruct.GPIO_Pin = PIN;
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_AN;
	GPIOInitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(PORT, &GPIOInitStruct);

}

void DigitalOut(GPIO_TypeDef* PORT, uint16_t PIN, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED)
{
	GPIO_InitTypeDef GPIOInitStruct;
	GPIO_StructInit(&GPIOInitStruct); // Default values - Input, PP, NoPull, VeryLow Speed

	GPIOInitStruct.GPIO_Pin = PIN;   // Specify pin
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_OUT;      //Config in output mode
	GPIOInitStruct.GPIO_OType = PushOrDrain;	  //Config Push-Pull or Open Drain
	GPIOInitStruct.GPIO_PuPd = PULL;	  // Pull UP/DOWN or Floating
	GPIOInitStruct.GPIO_Speed = SPEED;   // Chosen speed
	GPIO_Init(PORT, &GPIOInitStruct);
}

void DigitalIn(GPIO_TypeDef* PORT, uint16_t PIN, GPIOPuPd_TypeDef PULL)
{
	GPIO_InitTypeDef GPIOInitStruct;
	GPIO_StructInit(&GPIOInitStruct); // Default values - Input, PP, NoPull, VeryLow Speed

	GPIOInitStruct.GPIO_Pin = PIN;   			// Specify PIN
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_IN;      //Config input mode
	GPIOInitStruct.GPIO_OType = OutputPP;	  //Config Push-Pull mode
	GPIOInitStruct.GPIO_PuPd = PULL;	  // Pull UP/DOWN or Floating
	GPIO_Init(PORT, &GPIOInitStruct);
}

void AltFunc1(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION)
{
	GPIO_InitTypeDef GPIOInitStruct;
	GPIO_StructInit(&GPIOInitStruct); // Default values - Input, PP, NoPull, VeryLow Speed

	GPIOInitStruct.GPIO_Pin = PIN;   		 	 // Specify PIN
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_AF;     //Config Alternative function
	GPIOInitStruct.GPIO_OType = OutputPP;	 // Output type
	GPIOInitStruct.GPIO_PuPd = NoPull;
	GPIO_Init(PORT, &GPIOInitStruct);
	GPIO_PinAFConfig(GPIOA, PinToAFSource(PIN), FUNCTION);
}

void AltFunc2(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED)
{
	GPIO_InitTypeDef GPIOInitStruct;
	GPIO_StructInit(&GPIOInitStruct); // Default values - Input, PP, NoPull, VeryLow Speed

	GPIOInitStruct.GPIO_Pin = PIN;   		 	 // Specify PIN
	GPIOInitStruct.GPIO_Mode = GPIO_Mode_AF;     //Config Alternative function
	GPIOInitStruct.GPIO_OType = PushOrDrain;	 // Output type
	GPIOInitStruct.GPIO_PuPd = PULL;
	GPIOInitStruct.GPIO_Speed = SPEED;   // Chosen speed
	GPIO_Init(PORT, &GPIOInitStruct);
	GPIO_PinAFConfig(GPIOA, PinToAFSource(PIN), FUNCTION);
}


// ******************************** USART Functions **************************************
void USART_basic(uint32_t Baud, uint16_t WordLength, uint16_t Mode)
{
	USART_InitTypeDef USARTSetup;

	USARTSetup.USART_BaudRate = Baud;
	USARTSetup.USART_WordLength = WordLength;
	USARTSetup.USART_StopBits = USART_StopBits_1;
	USARTSetup.USART_Parity = USART_Parity_No;
	USARTSetup.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USARTSetup.USART_Mode = Mode;
	USART_Init(USART2, &USARTSetup); // Configure USART
	USART_Cmd(USART2, ENABLE); // Enable the USART
}

// **************************** NVIC Functions **********************************************
void InterruptEnable(uint8_t Channel, uint8_t Priority, uint8_t SubPriority)
{
	NVIC_InitTypeDef NVICSetup;				// Struct for NVIC config

	NVICSetup.NVIC_IRQChannel = Channel;
	NVICSetup.NVIC_IRQChannelPreemptionPriority = Priority;
	NVICSetup.NVIC_IRQChannelSubPriority = SubPriority;
	NVICSetup.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVICSetup);
}

void InterruptDisable(uint8_t Channel)
{
	/* Disable the Selected IRQ Channels -------------------------------------*/
	NVIC->ICER[Channel >> 0x05] = (uint32_t)0x01 << (Channel & (uint8_t)0x1F);
}
