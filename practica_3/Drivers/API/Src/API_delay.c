#include "API_delay.h"
#include "stm32f4xx_hal.h"

bool_t delayRead( delay_t * delay ) {
	if (!delay->running) {
		delay->running = true;
		delay->startTime = HAL_GetTick();
		return false;
	}
	delay->running = (HAL_GetTick() - delay->startTime) < delay->duration;
	return !delay->running;
}
void delayWrite( delay_t * delay, tick_t duration ){
	if (!delayIsRunning(delay)) {
		delay->duration = duration;
	}
}
void delayInit( delay_t * delay, tick_t duration ) {
	delay->duration = duration;
	delay->running = false;
}

bool_t delayIsRunning(delay_t * delay) {
	return delay->running;
}
