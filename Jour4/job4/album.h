#ifndef ALBUM_H
#define ALBUM_H

#include <stdlib.h>
#include <string.h>

struct album {
    char *title;
    char *artiste;
    int year;
    struct album *next;
};

// Prototypes des fonctions
struct album *create_album(const char *title, const char *artist, int year);
void print_album(const struct album *a);
void free_album(struct album *a);

#endif /* ALBUM_H */
