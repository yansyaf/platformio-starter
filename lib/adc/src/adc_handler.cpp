#include "adc_handler.h"
#include <stdbool.h>

#if defined(USE_ARDUINO)
    #include <Arduino.h>

    static bool adc_initialized = false;

    void adc_init() {
        if (!adc_initialized) {
            adc_initialized = true;
            analogReadResolution(12); // 12-bit resolution
            // analogSetAttenuation(ADC_11db); // Uncomment if needed
        }
    }

    uint16_t adc_read_value(uint8_t pin) {
        if (!adc_initialized) {
            adc_init();
        }

        return analogRead(pin);
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
#else
    #warning "Unknown platform for serial_wrapper"
    void adc_init() {}
    uint16_t adc_read_value(uint8_t pin) { return 0; }
#endif
