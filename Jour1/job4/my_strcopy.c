#include <unistd.h>

char *my_strcopy(char *dest, char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

int main() {
  char source[]= "Hello, World!";
  char destination[50];

  my_strcopy(destination, source);

  write(1, "Source: ", 8);
  write(1, source, 13);
  write(1, "\n", 1);
  write(1, "Destination: ", 13);
  write(1, destination, 13);
  write(1, "\n", 1);
}