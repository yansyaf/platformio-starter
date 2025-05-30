#include "fifo_handler.h"

#if !defined(USE_ARDUINO)
    #ifdef __cplusplus
    extern "C" {
    #endif
#endif

void fifo_init(fifo_t* fifo) {
    fifo->head = 0;
    fifo->tail = 0;
    fifo->count = 0;
}

bool fifo_push(fifo_t* fifo, fifo_item_t item) {
    if (fifo->count >= FIFO_SIZE) return false;

    fifo->buffer[fifo->head] = item;
    fifo->head = (fifo->head + 1) % FIFO_SIZE;
    fifo->count++;
    return true;
}

bool fifo_pop(fifo_t* fifo, fifo_item_t* item) {
    if (fifo->count == 0) return false;

    *item = fifo->buffer[fifo->tail];
    fifo->tail = (fifo->tail + 1) % FIFO_SIZE;
    fifo->count--;
    return true;
}

bool fifo_is_empty(const fifo_t* fifo) {
    return fifo->count == 0;
}

bool fifo_is_full(const fifo_t* fifo) {
    return fifo->count == FIFO_SIZE;
}

#if !defined(USE_ARDUINO)
    #ifdef __cplusplus
    }
    #endif
#endif
