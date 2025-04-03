#include <stdio.h> 
#include "album.h"
#include <stdlib.h>
#include <string.h>

void print_album(struct album *a) {
  if (a == NULL)
    return;
  printf("\"%s\" by \"%s\" released in %d.\n", a->title, a->title, a->year);
}

int main() {
  struct album *metallica_album = malloc(sizeof(struct album)); 
  if (!metallica_album)
    return 1;

  metallica_album->title = strdup("Master of Puppets");
  metallica_album->artiste = strdup("Metallica");
  metallica_album->year = 1986;

  print_album(metallica_album);

  free(metallica_album->title);
  free(metallica_album->artiste);
  free(metallica_album);

  return 0; 
}