#include "my_putchar.h"

void my_putstr(const char *str) {
  while (*str) {
    my_putchar(*str);
    str++;
  }
}