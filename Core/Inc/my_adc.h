#ifndef MY_ADC_H_
#define MY_ADC_H_

#include "main.h"

void choose_mux(uint8_t mux_number);
void choose_mux_channel(uint8_t num);
void delay_us(uint32_t us);
float read_voltage_adc1(void);
void read_all_batteries(void);


extern float voltages[13];
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

#endif
