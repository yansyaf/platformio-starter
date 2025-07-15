#ifndef EEPROM_HANDLER_H
#define EEPROM_HANDLER_H

#include <config.h>
#include <stddef.h>

void eeprom_init(size_t size = EEPROM_DEFAULT_SIZE); // If size == 0, use default
void eeprom_write_int(int address, int value);
void eeprom_write_string(int address, const char* data);
int eeprom_read_int(int address);
void eeprom_read_string(int address, char* out, size_t length);

#endif
