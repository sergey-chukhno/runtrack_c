#include <stdlib.h>
#include <string.h>
#include "album.h"

struct album *create_album(const char *title, const char *artist, int year) {
    struct album *new_album = malloc(sizeof(struct album));
    if (new_album == NULL) {
        return NULL;
    }

    new_album->title = strdup(title);
    new_album->artiste = strdup(artist);
    new_album->year = year;
    new_album->next = NULL; 

    return new_album;
}
