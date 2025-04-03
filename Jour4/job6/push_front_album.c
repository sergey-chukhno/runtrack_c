#include "album.h"
#include <stdlib.h>

void push_front_album(struct album **head, struct album *new_album) {
    if (new_album == NULL) {
        return;
    }

    new_album->next = *head; 
    *head = new_album; 
}
