#include <stdlib.h>

void delete_str_array(char ***strs) {
  if (strs == NULL || *strs == NULL) {
    return;
  }
  char **current = *strs;
  while (*current != NULL) {
    free(*current);
    current++; 
  }
  free(*strs);

  *strs = NULL;
}