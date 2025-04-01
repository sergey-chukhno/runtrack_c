#include <stdio.h>

void swap(int *a, int *b) {
  if (a == NULL || b == NULL) {
    return;
  }
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 10;
  int y = 5;
  printf("Before swap: x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("After swap: x = %d, y = %d\n", x, y);
  return 0;
}