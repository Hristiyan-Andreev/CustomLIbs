/*
 * hGPIO_LIB.h
 *
 *  Created on: Dec 3, 2017
 *      Author: Chris
 */
#include "stm32l1xx.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_usart.h"


#ifndef HGPIO_LIB_H_
#define HGPIO_LIB_H_

// **************** GPIO DEFINITIONS ******************************

#define NoPull GPIO_PuPd_NOPULL
#define PullUp GPIO_PuPd_UP
#define PullDown GPIO_PuPd_DOWN

#define VLowSpeed GPIO_Speed_400KHz
#define LowSpeed GPIO_Speed_2MHz
#define MedSpeed GPIO_Speed_10MHz
#define HighSpeed GPIO_Speed_40MHz

#define OutputPP GPIO_OType_PP
#define OutputOD GPIO_OType_OD

// *************** USART DEFINITIONS ********************************
#define USART_WL_8 USART_WordLength_8b
#define USART_WL_9 USART_WordLength_9b

#define USART_Tx USART_Mode_Tx
#define USART_Rx USART_Mode_Rx
#define USART_TRx USART_Mode_Tx | USART_Mode_Rx

// *************** NVIC DEFINITIONS ********************************

// *************** PROTOTYPES ********* PROTOTYPES *****************

// *************** GPIO PROTOTYPES *********************************
uint8_t PinToAFSource(uint16_t PIN);
void AnalogIn(GPIO_TypeDef* PORT, uint16_t PIN);
void DigitalOut(GPIO_TypeDef* PORT, uint16_t PIN, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED);
void DigitalIn(GPIO_TypeDef* PORT, uint16_t PIN, GPIOPuPd_TypeDef PULL);
void AltFunc1(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION);
void AltFunc2(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED);

// **************** USART PROTOTYPES ********************************
void USART_basic(uint32_t Baud, uint16_t WordLength, uint16_t Mode);

// **************** NVIC PROTOTYPES ********************************
void InterruptEnable(uint8_t Channel, uint8_t Priority, uint8_t SubPriority);
void InterruptDisable(uint8_t Channel);

#endif /* HGPIO_LIB_H_ */
