#include <unistd.h> 
#include "char_is_digit.h"

int str_is_digit(const char *str) {
  while (*str) {
    if (!char_is_digit(*str)) {
      return 0;
    }
    str++;
  }
  return 1; 
}

int main() {
  char myString [] = "123456789";
  if (str_is_digit(myString)) {
    write(1, "The string contains only digits.\n", 33);
  } else {
    write(1, "The string contains non-digit characters.\n", 42);
  }
  return 0;
}