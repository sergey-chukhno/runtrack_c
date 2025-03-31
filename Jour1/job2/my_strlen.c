#include <stdio.h>

  int my_strlen(char *str) {
    int len = 0; 
    while (str[len] != '\0') {
      len++;
    }
    return len;
  }

  int main() {
    char myString[] = "Hellow, World!";
    printf("Length: %d\n", my_strlen(myString));
    return 0; 
  }