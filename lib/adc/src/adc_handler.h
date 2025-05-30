#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H

#include <stdint.h>

void adc_init();
uint16_t adc_read_value(uint8_t pin);

#endif
