#include "album.h"
#include <stdlib.h>

void album_del_one(struct album **head, struct album *to_delete) {
    if (head == NULL || *head == NULL || to_delete == NULL) {
        return;
    }

    // if we delete the album that is in the head of the array 
    if (*head == to_delete) {
        *head = to_delete->next;  // Album next to him gets on head of the array 
    } else {
        // Looping through array to find the next album
        struct album *current = *head;
        while (current != NULL && current->next != to_delete) {
            current = current->next;
        }

        
        if (current != NULL && current->next == to_delete) {
            current->next = to_delete->next; 
        }
    }

    // Freeing memory
    
    free_album(to_delete);
}
