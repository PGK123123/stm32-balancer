#include "leds.h"

void led_on(uint8_t num) {
    switch(num) {
        case 1:  HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_SET); break;
        case 2:  HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_SET); break;
        case 3:  HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_SET); break;
        case 4:  HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_SET); break;
        case 5:  HAL_GPIO_WritePin(LED5_PORT, LED5_PIN, GPIO_PIN_SET); break;
        case 6:  HAL_GPIO_WritePin(LED6_PORT, LED6_PIN, GPIO_PIN_SET); break;
        case 7:  HAL_GPIO_WritePin(LED7_PORT, LED7_PIN, GPIO_PIN_SET); break;
        case 8:  HAL_GPIO_WritePin(LED8_PORT, LED8_PIN, GPIO_PIN_SET); break;
        case 9:  HAL_GPIO_WritePin(LED9_PORT, LED9_PIN, GPIO_PIN_SET); break;
        case 10: HAL_GPIO_WritePin(LED10_PORT, LED10_PIN, GPIO_PIN_SET); break;
        case 11: HAL_GPIO_WritePin(LED11_PORT, LED11_PIN, GPIO_PIN_SET); break;
        case 12: HAL_GPIO_WritePin(LED12_PORT, LED12_PIN, GPIO_PIN_SET); break;
        case 13: HAL_GPIO_WritePin(LED13_PORT, LED13_PIN, GPIO_PIN_SET); break;
        default: break;
    }
}


void led_off(uint8_t num) {
    switch(num) {
        case 1:  HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_RESET); break;
        case 2:  HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_RESET); break;
        case 3:  HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_RESET); break;
        case 4:  HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_RESET); break;
        case 5:  HAL_GPIO_WritePin(LED5_PORT, LED5_PIN, GPIO_PIN_RESET); break;
        case 6:  HAL_GPIO_WritePin(LED6_PORT, LED6_PIN, GPIO_PIN_RESET); break;
        case 7:  HAL_GPIO_WritePin(LED7_PORT, LED7_PIN, GPIO_PIN_RESET); break;
        case 8:  HAL_GPIO_WritePin(LED8_PORT, LED8_PIN, GPIO_PIN_RESET); break;
        case 9:  HAL_GPIO_WritePin(LED9_PORT, LED9_PIN, GPIO_PIN_RESET); break;
        case 10: HAL_GPIO_WritePin(LED10_PORT, LED10_PIN, GPIO_PIN_RESET); break;
        case 11: HAL_GPIO_WritePin(LED11_PORT, LED11_PIN, GPIO_PIN_RESET); break;
        case 12: HAL_GPIO_WritePin(LED12_PORT, LED12_PIN, GPIO_PIN_RESET); break;
        case 13: HAL_GPIO_WritePin(LED13_PORT, LED13_PIN, GPIO_PIN_RESET); break;
        default: break;
    }
}


void led_all_off(void) {
    HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED5_PORT, LED5_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED6_PORT, LED6_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED7_PORT, LED7_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED8_PORT, LED8_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED9_PORT, LED9_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED10_PORT, LED10_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED11_PORT, LED11_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED12_PORT, LED12_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED13_PORT, LED13_PIN, GPIO_PIN_RESET);
}


void led_set_balancing(float *voltages) {
    
    uint8_t max_index = 0;
    float max_voltage = voltages[0];
    
    for (uint8_t i = 1; i < 13; i++) {
        if (voltages[i] > max_voltage) {
            max_voltage = voltages[i];
            max_index = i;
        }
    }
    
    led_all_off();
    led_on(max_index + 1);
}