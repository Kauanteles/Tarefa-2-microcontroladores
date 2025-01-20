// bibliotecas usadas
#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

// Definição dos pinos GPIO
#define GPIO_VERDE 11
#define GPIO_AZUL 12
#define GPIO_VERMELHO 13
#define GPIO_BUZZER 21

// inicializa os pinos GPIO
void init_gpio()
{
    gpio_init(GPIO_VERMELHO);
    gpio_init(GPIO_VERDE);
    gpio_init(GPIO_AZUL);
    gpio_init(GPIO_BUZZER);

    gpio_set_dir(GPIO_VERMELHO, GPIO_OUT);
    gpio_set_dir(GPIO_VERDE, GPIO_OUT);
    gpio_set_dir(GPIO_AZUL, GPIO_OUT);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);
}

// executa os comandos dados pelo terminal
void ler_comando_terminal(const char *entrada_terminal)
{
    if (strcmp(entrada_terminal, "verde") == 0)
    {
        gpio_put(GPIO_VERDE, 1);
        gpio_put(GPIO_AZUL, 0);
        gpio_put(GPIO_VERMELHO, 0);
        gpio_put(GPIO_BUZZER, 0);
    }
    else if (strcmp(entrada_terminal, "azul") == 0)
    {
        gpio_put(GPIO_VERDE, 0);
        gpio_put(GPIO_AZUL, 1);
        gpio_put(GPIO_VERMELHO, 0);
        gpio_put(GPIO_BUZZER, 0);
    }
    else if (strcmp(entrada_terminal, "vermelho") == 0)
    {
        gpio_put(GPIO_VERDE, 0);
        gpio_put(GPIO_AZUL, 0);
        gpio_put(GPIO_VERMELHO, 1);
        gpio_put(GPIO_BUZZER, 0);
    }
    else if (strcmp(entrada_terminal, "ledsON") == 0)
    {
        gpio_put(GPIO_VERDE, 1);
        gpio_put(GPIO_AZUL, 1);
        gpio_put(GPIO_VERMELHO, 1);
    }
    else if (strcmp(entrada_terminal, "ledsOFF") == 0)
    {
        gpio_put(GPIO_VERDE, 0);
        gpio_put(GPIO_AZUL, 0);
        gpio_put(GPIO_VERMELHO, 0);
    }
    else if (strcmp(entrada_terminal, "buzzer") == 0)
    {
        for (int i = 0; i < 10000; i++)
        {
            gpio_put(GPIO_BUZZER, 1);
            sleep_us(50);
            gpio_put(GPIO_BUZZER, 0);
            sleep_us(50);
        }
    }
    else
    {
        printf("Comando inválido! Tente novamente.\n\n");
    }
}

int main()
{
    // Inicializa a placa
    stdio_init_all();
    init_gpio();

    // comandos validos
    printf("Lista de comandos possíveis:\n\n");
    printf("verde\n");
    printf("azul\n");
    printf("vermelho\n");
    printf("ledsON\n");
    printf("ledsOFF\n");
    printf("buzzer\n");

    // loop que mantem a execução, e pega as entradas do terminal
    while (1)
    {
        char entrada_terminal[8];

        if (scanf("%s", entrada_terminal))
        {
            ler_comando_terminal(entrada_terminal);
        }
    }
    return 0;
}
