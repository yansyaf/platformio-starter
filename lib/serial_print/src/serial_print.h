#ifndef SERIAL_PRINT_H
#define SERIAL_PRINT_H

#ifdef __cplusplus
extern "C" {
#endif

void serial_print_init(int baudrate);
void serial_print(const char *msg);
void serial_printf(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // SERIAL_PRINT_H
