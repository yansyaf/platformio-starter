#include "eeprom_handler.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef USE_ARDUINO
#include <EEPROM.h>
#endif

#if USE_ZEPHYR
    static unsigned char* eeprom_buffer = NULL;
    static size_t eeprom_size = 0;
#endif

void eeprom_init(size_t size) {
#ifdef USE_ARDUINO
    EEPROM.begin(size); // Required for ESP32
#elif USE_ZEPHYR
    if (eeprom_buffer != NULL) {
        free(eeprom_buffer);
    }

    eeprom_size = (size == 0) ? EEPROM_DEFAULT_SIZE : size;
    eeprom_buffer = malloc(eeprom_size);
    if (eeprom_buffer) {
        memset(eeprom_buffer, 0xFF, eeprom_size);  // Initialize as "empty"
    }
#endif
}

void eeprom_write_int(int address, int value) {
#ifdef USE_ARDUINO
    EEPROM.write(address, value);
    EEPROM.commit();
#elif USE_ZEPHYR
    if (!eeprom_buffer || address < 0 || address + sizeof(int) > eeprom_size)
        return;
    memcpy(&eeprom_buffer[address], &value, sizeof(int));
#endif
}

int eeprom_read_int(int address) {
#ifdef USE_ARDUINO
    return EEPROM.read(address);
#elif USE_ZEPHYR
    if (!eeprom_buffer || address < 0 || address + sizeof(int) > eeprom_size)
        return 0;
    int value;
    memcpy(&value, &eeprom_buffer[address], sizeof(int));
    return value;
#endif
}

void eeprom_write_string(int address, const String &data) {
#ifdef USE_ARDUINO
    for (size_t i = 0; i < data.length(); ++i) {
        EEPROM.write(address + i, data[i]);
    }
    EEPROM.write(address + data.length(), '\0'); // Null-terminate
    EEPROM.commit();
#elif USE_ZEPHYR
    if (!eeprom_buffer || !data) return;
    size_t len = strlen(data);
    if (address < 0 || address + len > eeprom_size) return;
    memcpy(&eeprom_buffer[address], data, len);
#endif
}

void eeprom_read_string(int address, char* out, size_t length) {
#ifdef USE_ARDUINO
    char buf[length + 1];
    for (size_t i = 0; i < length; ++i) {
        buf[i] = EEPROM.read(address + i);
    }
    buf[length] = '\0';
    out = buf;
#elif USE_ZEPHYR
    if (!eeprom_buffer || !out || address < 0 || address + length > eeprom_size) return;
    memcpy(out, &eeprom_buffer[address], length);
    out[length] = '\0';  // Null-terminate
#endif
}
