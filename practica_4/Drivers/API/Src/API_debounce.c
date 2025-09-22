#include "API_debounce.h"
#include "API_hardware.h"

typedef enum{
BUTTON_UP,
BUTTON_FALLING,
BUTTON_DOWN,
BUTTON_RAISING,
} debounceState_t;

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

static debounceState_t lastState;
static void (*actualFunction)(bool_t pin);
static void buttonUp(bool_t pin);
static void buttonDown(bool_t pin);
static bool_t wasPressed;

static void buttonTransition(bool_t pin) {
	if (pin) {
		lastState = BUTTON_DOWN;
		wasPressed = true;
		actualFunction = buttonDown;
	} else {
		lastState = BUTTON_UP;
		actualFunction = buttonUp;
	}
}

static void buttonUp(bool_t pin) {
	if (pin) {
		actualFunction = buttonTransition;
		lastState = BUTTON_FALLING;
	}
}

static void buttonDown(bool_t pin) {
	if (!pin) {
		actualFunction = buttonTransition;
		lastState = BUTTON_RAISING;
	}
}


void debounceFSM_init() {
	lastState = BUTTON_UP;
	actualFunction = buttonUp;
}
void debounceFSM_update(){
	bool_t pressed = !readPin();
	actualFunction(pressed);
}

bool_t readKey() {
	bool_t key = wasPressed;
	wasPressed = false;
	return key;
}
