#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // Biblioteca para controlar o hardware de PWM

#define PWM_SERVO 22 // Pino GPIO para o controle do servomotor
#define PWM_FREQUENCY 50 // Frequência do PWM (50Hz)
#define CLOCK_FREQUENCY 125000000 // Frequência do clock base do RP2040 (125MHz)
#define PWM_DIVISER 64.0 // Divisor de clock para PWM
#define WRAP_VALUE (CLOCK_FREQUENCY / (PWM_DIVISER * PWM_FREQUENCY)) // WRAP para 50Hz

// Ciclos de trabalho correspondentes aos ângulos do servo
#define SERVO_MIN (WRAP_VALUE * 0.025)  // 500 microsegundos -> 0 graus (2.5% duty cycle)
#define SERVO_MID (WRAP_VALUE * 0.0735) // 1470 microsegundos -> 90 graus (7.35% duty cycle)
#define SERVO_MAX (WRAP_VALUE * 0.12)   // 2400 microsegundos -> 180 graus (12% duty cycle)

#define SERVO_STEP 5 // Incremento/decremento do ciclo ativo
#define DELAY_MS 10  // Atraso de ajuste

// Função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM); // Habilitar GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO); // Obter slice do PWM

    pwm_set_clkdiv(slice, PWM_DIVISER); // Definir divisor de clock
    pwm_set_wrap(slice, WRAP_VALUE); // Definir o valor de wrap
    pwm_set_enabled(slice, true); // Habilitar PWM
}

// Função para definir o ângulo do servomotor
void set_servo_angle(uint16_t pulse_width) {
    pwm_set_gpio_level(PWM_SERVO, pulse_width); // Define o nível de PWM
    printf("Definindo PWM para %dus\n", pulse_width);
}

int main() {
    stdio_init_all(); // Inicializa sistema de I/O
    pwm_setup(); // Configura PWM

    // Posição 180° (2400us de ciclo ativo)
    set_servo_angle(SERVO_MAX);
    sleep_ms(5000);

    // Posição 90° (1470us de ciclo ativo)
    set_servo_angle(SERVO_MID);
    sleep_ms(5000);

    // Posição 0° (500us de ciclo ativo)
    set_servo_angle(SERVO_MIN);
    sleep_ms(5000);

    while (true) {
    }
}