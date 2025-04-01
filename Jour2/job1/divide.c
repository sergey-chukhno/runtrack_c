#include <stdio.h> 

void divide(int *val) {
  *val /= 2;
}

int main() {
  int val = 10;
  printf("Before division: %d\n", val);
  divide(&val);
  printf("After division: %d\n", val);
  return 0;
}