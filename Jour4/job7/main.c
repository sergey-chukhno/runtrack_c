#include <stdio.h>
#include "album.h"

int main() {
    struct album *album_list = NULL;

    
    struct album *album1 = create_album("Master of Puppets", "Metallica", 1986);
    struct album *album2 = create_album("Black Album", "Metallica", 1991);
    struct album *album3 = create_album("Ride the Lightning", "Metallica", 1984);

    if (!album1 || !album2 || !album3) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    //
    push_front_album(&album_list, album1);
    push_back_album(&album_list, album2);
    push_back_album(&album_list, album3);

    
    printf("Liste des albums avant la suppression :\n");
    struct album *current = album_list;
    while (current != NULL) {
        print_album(current);
        current = current->next;
    }

    
    album_del_one(&album_list, album2);

    
    printf("\nListe des albums après la suppression de l'album2 :\n");
    current = album_list;
    while (current != NULL) {
        print_album(current);
        current = current->next;
    }

    // Libération de la mémoire
    while (album_list != NULL) {
        struct album *temp = album_list;
        album_list = album_list->next;
        free_album(temp);
    }

    return 0;
}
