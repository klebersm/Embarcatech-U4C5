#include <stdio.h>
#include "pico/stdlib.h"
#include "U4C5.h"

int led = 0;

void init_gpio() {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_AMARERELO);
    gpio_set_dir(LED_AMARERELO, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
}

bool repeat_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, false);
    gpio_put(LED_AMARERELO, false);
    gpio_put(LED_VERDE, false);
    
    if(led == 0) gpio_put(LED_VERMELHO, true);
    if(led == 1) gpio_put(LED_AMARERELO, true);
    if(led == 2) gpio_put(LED_VERDE, true);

    led++;
    if(led == 3) led = 0;
}

int main() {
    stdio_init_all();

    init_gpio();
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeat_callback, NULL, &timer);

    while (true) {

        uint32_t start_ms = to_ms_since_boot(get_absolute_time());
        printf("Tempo absoluto: %d\n", start_ms);

        sleep_ms(1000);
    }
}
