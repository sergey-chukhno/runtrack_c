#ifndef ALBUM_H
#define ALBUM_H

struct album {
  char *title;
  char *artiste;
  int year;
};

/* Prototype of the function print_album */
void print_album(struct album *a);

#endif /*ALBUM_H*/