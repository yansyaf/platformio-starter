#ifndef FIFO_HANDLER_H
#define FIFO_HANDLER_H

#include <stdbool.h>
#include <stddef.h>
#include <config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int fifo_item_t;  // Change to the desired data type

typedef struct {
    fifo_item_t buffer[FIFO_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} fifo_t;

void fifo_init(fifo_t* fifo);
bool fifo_push(fifo_t* fifo, fifo_item_t item);
bool fifo_pop(fifo_t* fifo, fifo_item_t* item);
bool fifo_is_empty(const fifo_t* fifo);
bool fifo_is_full(const fifo_t* fifo);

#ifdef __cplusplus
}
#endif

#endif // FIFO_HANDLER_H
