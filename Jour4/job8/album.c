#include <stdio.h>
#include <stdlib.h>
#include "album.h"

void print_album(const struct album *a) {
    if (a != NULL) {
        printf("Album: %s | Artiste: %s | Année: %d\n", a->title, a->artiste, a->year);
    }
}

void free_album(struct album *a) {
    if (a != NULL) {
        free(a->title);
        free(a->artiste);
        free(a);
    }
}
