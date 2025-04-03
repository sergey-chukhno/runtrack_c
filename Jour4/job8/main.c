#include <stdio.h>
#include "album.h"

// Exemple de fonction de comparaison par année
int compare_by_year(const struct album *a, const struct album *b) {
    return a->year - b->year;  // Trie par année croissante
}

int main() {
    struct album *album_list = NULL;

    
    struct album *album1 = create_album("Master of Puppets", "Metallica", 1986);
    struct album *album2 = create_album("Black Album", "Metallica", 1991);
    struct album *album3 = create_album("Ride the Lightning", "Metallica", 1984);

    if (!album1 || !album2 || !album3) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    
    push_front_album(&album_list, album1);
    push_back_album(&album_list, album2);
    push_back_album(&album_list, album3);

    
    printf("Liste des albums avant le tri :\n");
    struct album *current = album_list;
    while (current != NULL) {
        print_album(current);
        current = current->next;
    }

    
    sort_album_by(album_list);

  
    printf("\nListe des albums après le tri par année :\n");
    current = album_list;
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
