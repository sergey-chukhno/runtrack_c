#ifndef ALBUM_H
#define ALBUM_H

#include <stdlib.h>
#include <string.h>

struct album {
  char *title;
  char *artiste;
  int year;
};


/* Prototypes of functions */
struct album *realloc_album(struct album *albums, int old_size, int new_size);
void init_album(struct album *a, const char *title, const char *artist, int year);
void print_album(const struct album *a);
void free_album_contents(struct album *a);

#endif /*ALBUM_H*/