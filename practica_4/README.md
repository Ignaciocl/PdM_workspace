# Práctica 3 - Retardos no bloqueantes en STM32

Este proyecto fue desarrollado en una placa **ST NUCLEO-F4xx** y tiene como objetivo implementar un módulo de software para trabajar con **retardos no bloqueantes**, utilizando como base las funciones de la **Práctica 2**.

## Autor
Ignacio Carol Lugones

---

## 📌 Objetivo
Encapsular las funciones necesarias para manejar retardos no bloqueantes dentro de una API propia, y utilizarlas para controlar el parpadeo de un LED en la placa NUCLEO-F4xx.

---

## 🗂️ Estructura del proyecto
Dentro del directorio `Drivers` se creó la carpeta `API` con las subcarpetas:

```
API/
 ├── Inc/
 │    └── API_delay.h
 └── Src/
      └── API_delay.c
```

- **`API_delay.h`**: contiene las definiciones, `typedef` y prototipos de funciones.
- **`API_delay.c`**: contiene la implementación de las funciones de la API.

> 🔹 Nota: Se debe agregar la carpeta `API/Inc` al *include path* del proyecto en Eclipse para que compile correctamente.

---

## ⚙️ Tipos y estructuras definidas
En `API_delay.h` se definen:

```c
typedef uint32_t tick_t;   // Requiere incluir <stdint.h>
typedef bool     bool_t;   // Requiere incluir <stdbool.h>

typedef struct {
    tick_t startTime;
    tick_t duration;
    bool_t running;
} delay_t;
```

### Funciones públicas
```c
void delayInit(delay_t * delay, tick_t duration);
bool_t delayRead(delay_t * delay);
void delayWrite(delay_t * delay, tick_t duration);
bool_t delayIsRunning(delay_t * delay);  // Punto 3
```

---

## 🔦 Punto 2 - Programa principal
Se implementó un programa que hace **titilar un LED en forma periódica** usando retardos no bloqueantes, siguiendo la secuencia:

```c
const uint32_t TIEMPOS[] = {500, 100, 100, 1000};
```

- Se utiliza una única variable `delay_t` para gestionar los retardos.
- Se aplica **duty cycle del 50%**, es decir, el LED permanece encendido y apagado el mismo tiempo en cada ciclo.
- Antes de modificar la duración del retardo con `delayWrite`, se verifica que el delay no esté corriendo usando la función `delayIsRunning`.

---

## ✅ Conclusión
Este ejercicio permitió:
- Practicar el encapsulamiento de código en una **API modular**.
- Implementar **retardos no bloqueantes** en un microcontrolador STM32.
- Controlar un LED de forma flexible utilizando una sola estructura `delay_t` y distintas duraciones.

---