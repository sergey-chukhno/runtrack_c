#include <stdio.h> 

void divide(int *val) {
  if (val != NULL) {
  *val /= 2;
  }
}

int main() {
  int num = 10;
  printf("Before division: %d\n", num);
  divide(&num);
  printf("After division: %d\n", num);
  return 0;
}