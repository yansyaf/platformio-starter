#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>

#if !defined(USE_ARDUINO)
    #ifdef __cplusplus
    extern "C" {
    #endif
#endif

void delay_ms(uint8_t period);

#if !defined(USE_ARDUINO)
    #ifdef __cplusplus
    }
    #endif
#endif

#endif
