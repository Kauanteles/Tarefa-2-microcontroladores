#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include <string.h>

// Definição dos GPIOs
#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

// Configuração da UART
#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1

// Funções para controle dos LEDs
void ligar_verde() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

void ligar_azul() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 0);
}

void ligar_vermelho() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 1);
}

void ligar_branco() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 1);
}

void desligar_todos() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

// Função para acionar o buzzer
void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000); // 2 segundos
    gpio_put(BUZZER, 0);
}

// Função para ler comandos da UART
void processar_comando(const char *comando) {
    if (strcmp(comando, "VERDE") == 0) {
        ligar_verde();
    } else if (strcmp(comando, "AZUL") == 0) {
        ligar_azul();
    } else if (strcmp(comando, "VERMELHO") == 0) {
        ligar_vermelho();
    } else if (strcmp(comando, "BRANCO") == 0) {
        ligar_branco();
    } else if (strcmp(comando, "DESLIGAR") == 0) {
        desligar_todos();
    } else if (strcmp(comando, "BUZZER") == 0) {
        acionar_buzzer();
    } else if (strcmp(comando, "REBOOT") == 0) {
        watchdog_reboot(0, 0, 0); // Reinicia o microcontrolador
    } else {
        uart_puts(UART_ID, "Comando invalido\n");
    }
}

int main() {
    // Inicialização da UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Configuração dos GPIOs
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(BUZZER);

    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);

    desligar_todos();
    gpio_put(BUZZER, 0);

    // Buffer para leitura de comandos
    char buffer[32];
    int idx = 0;

    uart_puts(UART_ID, "Sistema inicializado. Aguarde comandos via UART.\n");

    // Loop principal
    while (true) {
        // Verifica se há dados na UART
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID);

            if (c == '\n' || c == '\r') {
                buffer[idx] = '\0'; // Finaliza a string
                processar_comando(buffer);
                idx = 0; // Reinicia o índice do buffer
            } else if (idx < sizeof(buffer) - 1) {
                buffer[idx++] = c; // Armazena o caractere no buffer
            }
        }
    }

    return 0;
}
