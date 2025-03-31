#include <unistd.h>
#include <stdlib.h> // To use 'malloc'

char *my_strdup(const char *str) 
{
  int i = 0;

  while (str[i] != '\0') {
    i++;
  }


  //Allocate memory for a new characters chain including if it contains zero characterus

  char *copy = (char *)malloc(i + 1); 
  if (copy == NULL) {
    return NULL;
  }

  // Copy the chain into allocated memory
  for (int j = 0; j <= i; j++) {
    copy[j] = str[j]; 
  }
return copy; 
}

int main() {
  const char *source = "Hello, World!";

  // Calling my_strdup to create a source copy
  char *duplicate = my_strdup(source); 

  if (duplicate != NULL) {
    write(1, "Original: ", 10);
    write(1, source, 13);
    write(1, "\n", 1);

    write(1, "Duplicate: ", 11);
    write(1, duplicate, 13);
    write(1, "\n", 1);

    // Free allocated memory
    free(duplicate);
    } else {
      write(1, "Memory allocation failed\n", 25); 
    }
    return 0;
}
