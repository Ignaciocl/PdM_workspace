/*
 * API_hardware.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ignaciocl
 */

#include "API_hardware.h"
#include "stm32f4xx_hal.h"

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

void setPin(bool_t on) {
	HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, on);
}
void togglePin() {
  HAL_GPIO_TogglePin(B1_GPIO_Port, B1_Pin);
}
bool_t readPin() {
	return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
}
uint32_t getTick() {
	return HAL_GetTick();
}
