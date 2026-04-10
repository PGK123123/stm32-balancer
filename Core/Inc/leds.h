#ifndef LEDS_H
#define LEDS_H

#include "main.h"

// Список светодиодов согласно расположению
#define LED1_PIN    GPIO_PIN_1
#define LED1_PORT   GPIOA

#define LED2_PIN    GPIO_PIN_4
#define LED2_PORT   GPIOA

#define LED3_PIN    GPIO_PIN_5
#define LED3_PORT   GPIOA

#define LED4_PIN    GPIO_PIN_12
#define LED4_PORT   GPIOA

#define LED5_PIN    GPIO_PIN_11
#define LED5_PORT   GPIOA

#define LED6_PIN    GPIO_PIN_8
#define LED6_PORT   GPIOA

#define LED7_PIN    GPIO_PIN_7
#define LED7_PORT   GPIOA

#define LED8_PIN    GPIO_PIN_0
#define LED8_PORT   GPIOB

#define LED9_PIN    GPIO_PIN_9
#define LED9_PORT   GPIOA

#define LED10_PIN   GPIO_PIN_10
#define LED10_PORT  GPIOA

#define LED11_PIN   GPIO_PIN_1
#define LED11_PORT  GPIOB

#define LED12_PIN   GPIO_PIN_2
#define LED12_PORT  GPIOB

#define LED13_PIN   GPIO_PIN_7
#define LED13_PORT  GPIOB

// Прототипы функций
void led_on(uint8_t num);
void led_off(uint8_t num);
void led_all_off(void);
void led_set_balancing(float *voltages);

#endif
