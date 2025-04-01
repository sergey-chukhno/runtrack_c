#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

void strtoupper(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
      str[i] = toupper((unsigned char)str[i]);
  }
}

void strtolower(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
      str[i] = tolower((unsigned char)str[i]);
  }
}

void my_putstr(char *str) {
  printf("%s\n", str);
}

void func_to_array(char **array, void (*func)(char *)) {
  if (array == NULL || func == NULL) {
      return; 
  }

  int i = 0;
  while (array[i] != NULL) {
      char *copy = malloc(strlen(array[i]) + 1); // Allocate memory for the string
      if (copy == NULL) {
          printf("Memory allocation failed!\n");
          return;
      }
      strcpy(copy, array[i]); // Copy the string into newly allocated memory
      func(copy);  // Apply the function to the copied string
      free(copy);  // Free the allocated memory after use
      i++;
  }
}

int main() {
  char *array[] = {"Hello", "World", "example", NULL}; 

  printf("Applying strtoupper:\n");
  func_to_array(array, strtoupper);  

  printf("\nApplying strtolower:\n");
  func_to_array(array, strtolower);  

  printf("\nApplying my_putstr:\n");
  func_to_array(array, my_putstr);  

  return 0;
}
