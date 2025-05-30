#include "dac_handler.h"
#include <config.h>

#if defined(USE_ARDUINO)
    #include <Arduino.h>

    uint32_t max_value_for_bits(uint32_t bits) {
        if (bits >= 32) return 0xFFFFFFFF; // Avoid overflow
        return (1U << bits) - 1;
    }

    void dac_init() {
    #if defined(DAC1_PIN)
        pinMode(DAC1_PIN, OUTPUT);
    #endif
    #if defined(DAC2_PIN)
        pinMode(DAC2_PIN, OUTPUT);
    #endif
    }

    void dac_write(uint16_t level, uint8_t pin) {
        level = constrain(level, 0, 100);
        int dacValue = map(level, 0, 100, 0, max_value_for_bits(DAC_BIT_SIZE));
        dacWrite(pin, dacValue);
        Serial.printf("Set: %d → DAC: %d\n", level, dacValue);
    }

#elif defined(USE_ZEPHYR)
    #ifdef __cplusplus
    extern "C" {
    #endif

    #ifdef __cplusplus
    }
    #endif
#elif defined(USE_ESPIDF)
    #ifdef __cplusplus
    extern "C" {
    #endif
    
    #ifdef __cplusplus
    }
    #endif
#endif
