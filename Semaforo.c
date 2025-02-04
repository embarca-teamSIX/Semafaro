#include "Arduino.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Variável para armazenar o estado atual do semáforo
int estado = 0;

// Função de callback do temporizador
bool atualizar_semaforo(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    // Alterna o estado do semáforo
    switch (estado) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            estado = 1;
            break;
        case 1:
            gpio_put(LED_AMARELO, 1);
            estado = 2;
            break;
        case 2:
            gpio_put(LED_VERDE, 1);
            estado = 0;
            break;
    }
    return true; // Mantém o timer ativo
}

void setup() {
    Serial.begin(115200);  // Inicia a comunicação serial (opcional para debug)
    
    // Inicializa os pinos dos LEDs
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Configura o temporizador para mudar o semáforo a cada 3 segundos
    static struct repeating_timer timer;
    add_repeating_timer_ms(3000, atualizar_semaforo, NULL, &timer);
}

void loop() {
    // O loop principal pode ser mantido vazio, pois o timer gerencia os LEDs
    delay(100);
}
