#include <stdlib.h> 
#include <stdio.h>

int power(int n, int power) {

  // Checking for special cases 
  if (power == 0)
    return 1; 
  if (power < 0)
    return 0; 
  if (n == 0)
    return 0;
  if (n == 1)
    return 1; 
  

  // Allocating memory to stock intermediary result
  int *result = malloc(sizeof(int));
  if (result == NULL)
    return 0; // Memory allocation failed
  *result = 1;

  for (int i = 0; i < power; i++) {
    *result *= n; 
  }
  int final_result = *result;
  free(result);

  return final_result; 
}

int main(void) {
  printf("2^2 = %d (expected: 4)\n", power(2, 2));
  printf("2^3 = %d (expected: 8)\n", power(2, 3));

  return 0;
}