#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Function to compare strings 
int string_compare(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

//Bubble sort function 
void sort(char **array) {
  if (array == NULL) {
    return;
  }
  // Counting the number of elements of the array
  int count = 0; 
  while (array[count] != NULL) {
    count++;
  }
  //Sorting
  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count -i - 1; j++) {
      if (string_compare(array[j], array[j+1]) > 0) {
        //Swap pointers
        char *temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp; 
      }
    }
  }
}

int main() {
  char *array[] = {"ABC", "GHJ", "DEF", "OPQ", "XYZ", "KLM", NULL};
  printf("Array before sorting: \n");
  for (int i = 0; array[i] != NULL; i++) {
    printf("%s\n", array[i]); 
  }

  sort(array);

  printf("After sorting: \n");
  for (int i = 0; array[i] != NULL; i++) {
    printf("%s\n", array[i]);
  }

  return 0;
}