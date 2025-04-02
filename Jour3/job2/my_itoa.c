#include <stdio.h> 
#include <string.h> 

char *my_itoa(int n) {
  int temp = 0;
  int length = 0;
  int is_negative = 0;
  char *result; 

  //Handling the special case if num is '0'
  if (n == 0) {
    result = malloc(2); //"0\0 = 2 characters"
    if (result == NULL) return NULL;
    result[0] = '0';
    result[1] = '\0';
    return result;
  }
  if (n < 0) {
    is_negative = 1;
    length++;
    temp = -n;
  } else {
    temp = n; 
  }
  while (temp > 0) {
    length++;
    temp /= 10; 
  }
  // Allocating memory for chain length (length + '\0')
  result = malloc(length + 1);
  if (result == NULL)
    return NULL;

  result[length] = '\0'; 

  // Restauring n to its original value 
  if (n<0) {
    result[0] = '-';
    n = -n; 
  }
  // Writing in the chain from left to right
  temp = n;
  int i = length-1;
  while((is_negative && i>0) || (!is_negative && i>= 0)) {
      result[i] = (temp % 10) + '0'; // We are doing the opposite of what we did in Job1
      temp /= 10;
      i--;
    }
  return result; 
}