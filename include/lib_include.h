/**
 * Only edit this file if you modify (add, remove) lib 
 */
#include <config.h>

#if USE_ADC
#include "adc_handler.h"
#endif
#if USE_DAC
#include "dac_handler.h"
#endif
#if USE_DELAY
#include "delay_handler.h"
#endif
#if USE_FIFO
#include "fifo_handler.h"
#endif
#if USE_SERIAL_PRINT
#include "serial_print.h"
#endif
#if USE_WIFI
#include "wifi_handler.h"
#endif
#if USE_MQTT
#include "mqtt_handler.h"
#endif
#if USE_EEPROM
#include "eeprom_handler.h"
#endif