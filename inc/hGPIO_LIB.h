/*
 * hGPIO_LIB.h
 *
 *  Created on: Dec 3, 2017
 *      Author: Chris
 */
#include "stm32l1xx.h"
#include "stm32l1xx_gpio.h"


#ifndef HGPIO_LIB_H_
#define HGPIO_LIB_H_


#define NoPull GPIO_PuPd_NOPULL
#define PullUp GPIO_PuPd_UP
#define PullDown GPIO_PuPd_DOWN

#define VLowSpeed GPIO_Speed_400KHz
#define LowSpeed GPIO_Speed_2MHz
#define MedSpeed GPIO_Speed_10MHz
#define HighSpeed GPIO_Speed_40MHz

#define OutputPP GPIO_OType_PP
#define OutputOD GPIO_OType_OD


uint8_t PinToAFSource(uint16_t PIN);
void AnalogIn(GPIO_TypeDef* PORT, uint16_t PIN);
void DigitalOut(GPIO_TypeDef* PORT, uint16_t PIN, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED);
void DigitalIn(GPIO_TypeDef* PORT, uint16_t PIN, GPIOPuPd_TypeDef PULL);

void AltFunc1(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION);
void AltFunc2(GPIO_TypeDef* PORT, uint16_t PIN, uint8_t FUNCTION, GPIOOType_TypeDef PushOrDrain,
										GPIOPuPd_TypeDef PULL, GPIOSpeed_TypeDef SPEED);

#endif /* HGPIO_LIB_H_ */
