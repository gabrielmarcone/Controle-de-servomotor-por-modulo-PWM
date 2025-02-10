#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // Biblioteca para controlar o hardware de PWM

#define PWM_LED_BLUE 12 // LED azul conectado a GPIO como PWM
#define SERVO_PIN 22 // Pino do servo motor

#define WRAP_PERIOD 20000 // Valor máximo atingido pelo contador - WRAP
#define PWM_DIVISER 1.25 // Divisor do clock para o PWM
#define PWM_FREQ 50 // Frequência do PWM

// Ciclos de trabalho correspondentes aos ângulos do servo
#define SERVO_MIN 500   // 500 microsegundos -> 0 graus (2.5% duty cycle)
#define SERVO_MID 1470  // 1470 microsegundos -> 90 graus (7.35% duty cycle)
#define SERVO_MAX 2400  // 2400 microsegundos -> 180 graus (12% duty cycle)


int main() {
    stdio_init_all();

    while (true) {
    }
}