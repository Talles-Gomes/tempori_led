#include <stdio.h>
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas como GPIO.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define ledR 11 // verde na placa BitDogLab
#define ledY 12 // azulna placa BitDogLab
#define ledG 13 // vermelho na placa BitDogLab
bool led_on = false;
int a=0;
bool repeating_timer_callback(struct repeating_timer *t) {

  switch(a){
    case 0: printf("sinal vermelho\n");
            
            gpio_put(ledR,true);
            gpio_put(ledY,false);
            gpio_put(ledG,false);
            a++;
    break;
    case 1: printf("sinal amarelo\n");
            
            gpio_put(ledR,false);
            gpio_put(ledY,true);
            gpio_put(ledG,false);
            a++;
    break;
    case 2: printf("sinal verde\n");
            
            gpio_put(ledR,false);
            gpio_put(ledY,false);
            gpio_put(ledG,true);
            a=0;
    break;
  }
return true;
 }

int main() {
// Inicializa a comunicação serial
stdio_init_all();
 // Inicialização dos pinos dos leds
gpio_init(ledR);
gpio_set_dir(ledR,true);

gpio_init(ledY);
gpio_set_dir(ledY,true);

gpio_init(ledG);
gpio_set_dir(ledG,true);

// Declaração de uma estrutura de temporizador de repetição.
// Esta estrutura armazenará informações sobre o temporizador configurado.
struct repeating_timer timer;

// Configura o temporizador para chamar a função de callback a cada 1 segundo.
add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

// Loop infinito que mantém o programa em execução.
while (true) {
// Pausa de 1 segundos para reduzir o uso da CPU.
sleep_ms(1000);
printf("Confira o sinal antes de atravessar\n");
}
 return 0;
 }