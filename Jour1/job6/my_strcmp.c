#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
  int i = 0; 

  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i]) {
      return s1[i] - s2[i];
    }
    i++;
  }
  return s1[i] - s2[i];
}

int main() {
  const char *s1 = "Hello";
  const char *s2 = "Hello";
  const char *s3 = "Hello, World!";
  const char *s4 = "Hello";

  int result1 = my_strcmp(s1, s2);
  int result2 = my_strcmp(s3, s4);

  char buffer[50];
  int length;

  length = snprintf(buffer, sizeof(buffer), "Result of my_strcmp(s1, s2): %d\n", result1);
  write(1, buffer, length);

  length = snprintf(buffer, sizeof(buffer), "Result of my_strcmp(s3, s4): %d\n", result2);
  write(1, buffer, length);
  return 0;
}