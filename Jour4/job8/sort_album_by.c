#include "album.h"
#include <stddef.h>

// Fonction de tri des albums par année de sortie
void sort_album_by(struct album *head) {
    if (head == NULL || head->next == NULL) {
        return;  // Liste vide ou un seul élément, pas besoin de trier
    }

    int swapped;
    struct album *current;
    struct album *prev = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != NULL) {
            // Comparaison of the albums by year
            if (current->year > current->next->year) {
              
                struct album temp = *current;
                *current = *current->next;
                *current->next = temp;

                swapped = 1;  
            }
            current = current->next;
        }
    } while (swapped);  
}

