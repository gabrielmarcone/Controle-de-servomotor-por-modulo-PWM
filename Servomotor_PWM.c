#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // Biblioteca para controlar o hardware de PWM

#define PWM_LED_BLUE 12 // Pino GPIO para o LED azul
#define PWM_SERVO 22 // Pino GPIO para o controle do servomotor
#define PWM_FREQUENCY 50 // Frequência do PWM (50Hz)
#define CLOCK_FREQUENCY 125000000 // Frequência do clock base do RP2040 (125MHz)
#define PWM_DIVISER 125.0 // Divisor de clock para PWM
#define WRAP_VALUE 20000 // WRAP para 50Hz

// Ciclos de trabalho correspondentes aos ângulos do servo
#define SERVO_MIN (WRAP_VALUE * 0.025)  // 500 microsegundos -> 0 graus (2.5% duty cycle)
#define SERVO_MID (WRAP_VALUE * 0.0735) // 1470 microsegundos -> 90 graus (7.35% duty cycle)
#define SERVO_MAX (WRAP_VALUE * 0.12)   // 2400 microsegundos -> 180 graus (12% duty cycle)

#define SERVO_STEP 5 // Incremento/decremento do ciclo ativo
#define DELAY_MS 10  // Atraso de ajuste

// Função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM); // Habilitar GPIO 22 como PWM para o servomotor
    gpio_set_function(PWM_LED_BLUE, GPIO_FUNC_PWM); 
    uint slice_servo = pwm_gpio_to_slice_num(PWM_SERVO); // Obter slice do PWM da GPIO 22
    uint slice_led = pwm_gpio_to_slice_num(PWM_LED_BLUE); // Obter slide do PWM da GPIO 12

    pwm_set_clkdiv(slice_servo, PWM_DIVISER); // Definir divisor de clock
    pwm_set_wrap(slice_servo, WRAP_VALUE); // Definir o valor de wrap
    pwm_set_enabled(slice_servo, true); // Habilitar PWM

    pwm_set_clkdiv(slice_led, PWM_DIVISER); // Definir divisor de clock para LED
    pwm_set_wrap(slice_led, WRAP_VALUE); // Definir o valor de wrap para LED
    pwm_set_enabled(slice_led, true); // Habilitar PWM para LED
}

// Função para definir o ângulo do servomotor
void set_servo_angle(uint16_t pulse_width) {
    pwm_set_gpio_level(PWM_SERVO, pulse_width); // Define o nível de PWM
    pwm_set_gpio_level(PWM_LED_BLUE, pulse_width); // Define o nível de PWM para o LED
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
         // Movimentação suave de 0° a 180° com LED acompanhando
         for (uint16_t pos = SERVO_MIN; pos <= SERVO_MAX; pos += SERVO_STEP) {
            set_servo_angle(pos);
            sleep_ms(DELAY_MS);
        }

        // Movimentação suave de 180° a 0° com LED acompanhando
        for (uint16_t pos = SERVO_MAX; pos >= SERVO_MIN; pos -= SERVO_STEP) {
            set_servo_angle(pos);
            sleep_ms(DELAY_MS);
        }
    }
}