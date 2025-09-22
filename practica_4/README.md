# Práctica 4 - Anti-rebounce FSM on STM32

This project was developed on an **ST NUCLEO-F4xx** board and implements a **Finite State Machine (FSM)** to handle button debouncing in software, based on the non-blocking delays created in **Practice 3**.

---

## 📌 Objective
- Implement a software FSM to correctly read the push-button state, ignoring contact bouncing.
- Trigger actions/events on button **press** (falling edge) and **release** (rising edge).
- Use a **non-blocking delay of 40 ms** for debouncing.

---

## 🗂️ Project Structure
A new project was created as a copy of Practice 3, with the following additional modules:

```
Drivers/
 └── API/
      ├── Inc/
      │    └── API_debounce.h
      └── Src/
           └── API_debounce.c
```

- **`API_debounce.h`**: public function prototypes and declarations.
- **`API_debounce.c`**: private declarations, state machine implementation, and logic.

---

## ⚙️ FSM Definition
The FSM manages four states:

```c
typedef enum {
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RAISING
} debounceState_t;
```

- **Initial state:** `BUTTON_UP`.
- **Transition conditions:** Based on button input with debouncing delay.

---

## 🔦 Functions
### Public functions in `API_debounce.h`
```c
void debounceFSM_init(void);
void debounceFSM_update(void);
bool_t readKey(void);
```

- **`debounceFSM_init()`** → Initializes the FSM in `BUTTON_UP`.
- **`debounceFSM_update()`** → Must be called periodically. Handles state transitions and debounce timing.
- **`readKey()`** → Returns `true` once if the button was pressed (falling edge), then resets its internal flag to `false`.

### Private implementation in `API_debounce.c`
- `debounceState_t` declared as a **private global variable** (`static`).
- Internal flag (`bool_t wasPressed`) set on falling edge and cleared on `readKey()`.

---

## 🚦 Main Program Behavior
The `main.c` program integrates both **API_delay** (from Practice 3) and **API_debounce** to control the LED:

- The LED toggles with a duty cycle of **50%**.
- Default blink period is **500 ms**.
- Each button press (detected via `readKey()`) switches the LED blink period between:
  - **100 ms**
  - **500 ms**

---

## ✅ Conclusion
This practice consolidates:
- Use of **modular APIs** (`API_delay` and `API_debounce`).
- Implementation of an **anti-bounce FSM** using non-blocking delays.
- Event-driven programming by reacting to button edges (press/release).
- A flexible LED blinking system controlled via button input.

---
