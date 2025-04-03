#include <stdio.h>
#include "album.h"

int main() {
    struct album *album_list = NULL;

  
    struct album *album1 = create_album("Master of Puppets", "Metallica", 1986);
    struct album *album2 = create_album("Black Album", "Metallica", 1991);
    struct album *album3 = create_album("Ride the Lightning", "Metallica", 1984);

    if (!album1 || !album2 || !album3) {
        fprintf(stderr, "Erreur of memory allocation\n");
        return 1;
    }

    // Ajout en début de liste
    push_front_album(&album_list, album1);
    push_front_album(&album_list, album2);
    push_front_album(&album_list, album3);

    // Affichage des albums
    printf("List of albums (new one added in head) :\n");
    struct album *current = album_list;
    while (current != NULL) {
        print_album(current);
        current = current->next;
    }

  
    while (album_list != NULL) {
        struct album *temp = album_list;
        album_list = album_list->next;
        free_album(temp);
    }

    return 0;
}
