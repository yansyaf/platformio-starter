#ifndef DAC_HANDLER_H
#define DAC_HANDLER_H

#include <stdint.h>

void dac_init();
void dac_write(uint16_t value, uint8_t pin);

#endif
