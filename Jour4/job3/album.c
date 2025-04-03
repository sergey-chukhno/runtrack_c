#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"

void init_album(struct album *a, const char *title, const char *artist, int year) {
    a->title = strdup(title);
    a->artiste = strdup(artist);
    a->year = year;
}

void print_album(const struct album *a) {
    printf("Album: %s | Artiste: %s | Année: %d\n", a->title, a->artiste, a->year);
}

void free_album_contents(struct album *a) {
    free(a->title);
    free(a->artiste);
}
