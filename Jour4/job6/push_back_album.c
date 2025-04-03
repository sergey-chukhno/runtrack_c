#include "album.h"
#include <stdlib.h>

void push_back_album(struct album **head, struct album *new_album) {
    if (new_album == NULL) {
        return;
    }

    if (*head == NULL) { 
        *head = new_album; // the array is empty, we add a new album
        return;
    }

    struct album *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_album; // Add to the end
}