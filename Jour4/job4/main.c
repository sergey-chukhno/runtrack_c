#include <stdio.h>
#include "album.h"

int main() {
    struct album *album1 = create_album("Master of Puppets", "Metallica", 1986);
    if (album1 == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    print_album(album1);
    
    free_album(album1);

    return 0;
}
