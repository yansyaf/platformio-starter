#include <stdio.h>
#include <lib_include.h>
#include <version.h>

#ifdef __cplusplus
extern "C" {
#endif

void app_main(void) {
  // variable declaration
  fifo_t my_fifo;

  // library initialization
  fifo_init(&my_fifo);
  serial_print_init();

  // FIFO write n read
  serial_print("Pushing values to FIFO:\n");
  for (int i = 1; i <= 10; ++i) {
    if (fifo_push(&my_fifo, i)) {
      serial_printf("Pushed: %d\n", i);
    } else {
      serial_printf("FIFO Full. Could not push: %d\n", i);
    }
  }

  serial_print("\nPopping values from FIFO:\n");
  fifo_item_t value;
  while (!fifo_is_empty(&my_fifo)) {
    if (fifo_pop(&my_fifo, &value)) {
      serial_printf("Popped: %d\n", value);
    }
  }
}

#ifdef __cplusplus
}
#endif