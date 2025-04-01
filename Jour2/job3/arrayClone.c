#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

//Function to copy an array of characters 
char **array_clone(char **array, int n) {
  if (array == NULL || n <= 0) {
    return NULL;
  }
  //Counting the number of elements to copy
  int count = 0; 
  while (count < n && array[count] != NULL) {
    count++;
  }

  //Allocating memory for a new array
  char **clone = malloc((count + 1) * sizeof(char *));
  if (clone == NULL) {
    return NULL; // Memory allocation failed; 
  }
  //Copying a chain of characters
  for (int i = 0; i < count; i++) {
    clone[i] = malloc(strlen(array[i]) + 1); // Allocating memory
    if (clone[i] == NULL) {
      for (int j = 0; j < count; j++) {
        free(clone[j]);
      }
      free(clone);
      return NULL; 
    }
    strcpy(clone[i], array[i]); // Copy the chain
  }
  clone[count] = NULL; //Terminate by NULL pointer
  return clone;
}

int main() {
  char *array[] = {"Hello", "World", "C", "malloc", "realloc", NULL};
  int n = 5;

  char **clone = array_clone(array, n); 

  if (clone != NULL) {
    for (int i = 0; clone[i] != NULL; i++) {
      printf("%s\n", clone[i]); 
    }
    free(clone); 
  }
  return 0; 
}