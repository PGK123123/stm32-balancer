#include "my_adc.h"
#define AVG_COUNT 50


void choose_mux_channel(uint8_t num){
   GPIOB->ODR &= ~(GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6);
    if (num & 0x01) GPIOB->ODR |= GPIO_PIN_4;  // бит 0 > PB4
    if (num & 0x02) GPIOB->ODR |= GPIO_PIN_5;  // бит 1 > PB5
    if (num & 0x04) GPIOB->ODR |= GPIO_PIN_6;  // бит 2 > PB6
		delay_us(5);
}
void delay_us(uint32_t us) {
    for (volatile uint32_t i = 0; i < us * 16; i++) {
        __NOP();
    }
}


float voltages[13];
static char message[150];
static char temp[20];

float read_voltage_adc1(void) {
    
		uint32_t sum = 0;
    for (uint16_t i = 0; i < AVG_COUNT; i++) {
        HAL_ADC_PollForConversion(&hadc1, 10);
        sum+= HAL_ADC_GetValue(&hadc1);
        }

    uint32_t avg_raw = sum / AVG_COUNT;
    return (avg_raw * 3.3f) / 4095.0f;
				
				
}


void choose_mux(uint8_t number){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2 | GPIO_PIN_8, GPIO_PIN_SET);
  delay_us(2);  // твоя функция микросекундной задержки
	if (number == 1) {
        // Первый мультиплексор активен, второй отключён
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET); // PB2 = 0
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // PB8 = 1
    } 
    else if (number == 2) {
        // Второй мультиплексор активен, первый отключён
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);   // PB2 = 1
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); // PB8 = 0
    }
	delay_us(2);
}




void read_all_batteries(void){
    message[0] = '\0';
    choose_mux(1);
    for (uint8_t i = 0; i < 8; i++) {
        choose_mux_channel(i);
				voltages[i] = read_voltage_adc1();
        sprintf(temp, "%d:%.2f ", i+1, voltages[i]);
        strcat(message, temp);
    }
    choose_mux(2);
    for (uint8_t i = 0; i < 5; i++) {
        choose_mux_channel(i);
				voltages[i+8] = read_voltage_adc1();
        sprintf(temp, "%d:%.2f ", i+9, voltages[i+8]);
        strcat(message, temp);
    }
    
    strcat(message, "\r\n");
    HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), 100);
}
