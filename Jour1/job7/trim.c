#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *trim(const char *src) {
  int i = 0;
  int start = 0;
  int end = 0; 

  //Find the first non-space character
  while (src[start] == ' ' || src[start] == '\t' || src[start] == '\n') {
    start++;
  }

  //Find the last non-space character
  end = start;
  while (src[end] != '\0') {
    end++;
  }
  end--;
  while (end > start && (src[end] == ' ' || src[end] == '\t' || src[end] == '\n')) {
    end--;
  }

  //if the string is empty after trimming
  if (start>end) {
    return NULL;
  }

  //Allocate memory for new string
  char *result = (char *)malloc(end - start + 2); //+2 for the null terminator
  if (result == NULL) {
    return NULL; // Memory allocation failed
  }

  //Copy the trimmed part of the source to the new string
  while (start <= end) {
    result[i++] = src[start++];
  }
  result[i] = '\0'; //Add the null terminator

  return result; 
}

int main() {
  const char *source = " Hello World  \n";
  char *trimmed = trim(source); 

  if (trimmed != NULL) {
    write(1, "Trimmed string: '", 17);
    write(1, trimmed, 13);
    write(1, "'\n", 2);

    free(trimmed); // Freeing allocated memory
  } else {
    write(1, "Error: memory allocation failed\n", 32);
  }
  return 0; 
}
