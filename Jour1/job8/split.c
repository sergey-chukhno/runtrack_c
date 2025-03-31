#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_words(const char *str) {
  int count = 0;
  int in_word = 0; 

  while (*str) {
    if (*str == ' ' || *str == '\t' || *str == '\n') {
      in_word = 0; //we are not 'within' a word
    } else if (!in_word) {
      in_word = 1; // A word begins
      count++;
    }
    str++;
  }
  return count;
}

char **split(const char *str) {
  int num_words = count_words(str);
  char **result = (char **)malloc((num_words + 1) * sizeof(char *)); //+1 for NULL
  if (!result)
    return NULL;

  int i = 0; 
  while (*str) {
    while (*str == ' ' || *str =='\t' || *str == '\n')
      str++; //To ignore spaces
    if (*str) {
      const char *start = str;
      while (*str && *str != ' ' && *str != '\t' && *str != '\n')
        str++;

      int length = str - start;
      result[i] = (char *)malloc(length + 1);
      if (!result[i])
        return NULL; //if malloc fails to allocate memory

      for (int j = 0; j < length; j++) {
        result[i][j] = start[j];
      }
      result[i][length] = '\0'; //End the word
      i++;
    }  
  }
  result[i] = NULL; // End the table of characters

  return result; 
}

int main() {
  const char *src = "   hello , World   have fun  ";
  char **words = split(src); 
  int i;

  if (words) {
    for (i = 0; words[i] != NULL; i++) {
      printf("Word %d: '%s'\n", i + 1, words[i]);
      free(words[i]);
    }
    free(words);
  } else {
    printf("Memory allocation failed\n");
  }
  return 0;
}