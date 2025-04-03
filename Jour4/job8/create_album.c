#include "album.h"
#include <stdlib.h>
#include <string.h>

struct album *create_album(const char *title, const char *artist, int year) {
    struct album *new_album = (struct album *)malloc(sizeof(struct album));
    if (new_album == NULL) {
        return NULL;
    }

    new_album->title = strdup(title);  
    new_album->artiste = strdup(artist);
    new_album->year = year;
    new_album->next = NULL;

    if (new_album->title == NULL || new_album->artiste == NULL) {
        free(new_album->title);
        free(new_album->artiste);
        free(new_album);
        return NULL;
    }

    return new_album;
}