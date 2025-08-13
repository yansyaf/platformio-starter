#include "serial_print.h"
#include <stdarg.h>
#include <stdio.h>

#if defined(USE_ARDUINO)
    #include <Arduino.h>

    void serial_print_init(int baudrate) {
        Serial.begin(baudrate);
        while (!Serial) { ; }
    }

    void serial_print(const char *msg) {
        Serial.print(msg);
    }

    void serial_printf(const char *fmt, ...) {
        char buffer[256];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        va_end(args);
        Serial.print(buffer);
    }

#elif defined(USE_ZEPHYR)
    #include <zephyr/kernel.h>
    #include <zephyr/sys/printk.h>

    #ifdef __cplusplus
    extern "C" {
    #endif

    void serial_print_init(void) {
        // No init needed for printk
    }

    void serial_print(const char *msg) {
        printk("%s", msg);
    }

    void serial_printf(const char *fmt, ...) {
        va_list args;
        va_start(args, fmt);
        vprintk(fmt, args);
        va_end(args);
    }

    #ifdef __cplusplus
    }
    #endif

#elif defined(USE_ESPIDF)
    #include "esp_log.h"

    #ifdef __cplusplus
    extern "C" {
    #endif

    static const char *TAG = "SerialWrapper";

    void serial_print_init(void) {
        // No init needed
    }

    void serial_print(const char *msg) {
        ESP_LOGI(TAG, "%s", msg);
    }

    void serial_printf(const char *fmt, ...) {
        va_list args;
        va_start(args, fmt);
        esp_log_writev(ESP_LOG_INFO, TAG, fmt, args);
        va_end(args);
    }

    #ifdef __cplusplus
    }
    #endif

#else
    #warning "Unknown platform for serial_wrapper"
    void serial_print_init(void) {}
    void serial_print(const char *msg) { (void)msg; }
    void serial_printf(const char *fmt, ...) { (void)fmt; }
#endif
