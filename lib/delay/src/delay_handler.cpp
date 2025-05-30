#include "delay_handler.h"

#if defined(USE_ARDUINO)
    #include <Arduino.h>
    void delay_ms(uint8_t period) {
        delay(period);
    }
#elif defined(USE_ZEPHYR)
    #ifdef __cplusplus
    extern "C" {
    #endif

    void delay_ms(uint8_t period) {
        k_sleep(K_MSEC(period)); 
    }

    #ifdef __cplusplus
    }
    #endif
#elif defined(USE_ESPIDF)
    #ifdef __cplusplus
    extern "C" {
    #endif

    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"

    void delay_ms(uint8_t period) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    #ifdef __cplusplus
    }
    #endif
#else
    #warning "Unknown platform for delay"
    void delay_ms(uint8_t period) {}
#endif
