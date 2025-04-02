#include <stdlib.h> 
#include <stdio.h> 

int my_sqrt(int num) {
  if (num < 0)
    return 0;

  for (int i = 0; i * i <= num; i++) {
    if (i * i == num) {
      return i; 
    }
  }
    return 0; // We return 0 if the sqr of n is not an integer
}

int main(void) {
  int num = 4;
  printf("Square root of num is: %d\n", my_sqrt(num));

  num = 5;
  printf("Square root of num is: %d\n", my_sqrt(num));

  return 0; 
}