#include <stdio.h>
#include <stdlib.h>
#include "album.h"

struct album *realloc_album(struct album *albums, int old_size, int new_size) {
    if (new_size <= 0) {
        for (int i = 0; i < old_size; i++) {
            free_album_contents(&albums[i]);
        }
        free(albums);
        return NULL;
    }

    // Allocating memory for a new albums array
    struct album *new_albums = malloc(new_size * sizeof(struct album));
    if (new_albums == NULL) {
        return NULL;
    }

    // Copying old albums into new array
    int copy_size = (old_size < new_size) ? old_size : new_size;
    for (int i = 0; i < copy_size; i++) {
        new_albums[i] = albums[i]; 
    }

    
    free(albums);

    return new_albums;
}

int main() {
    int initial_size = 2;
    
    struct album *albums = malloc(initial_size * sizeof(struct album));
    if (albums == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return 1;
    }

    init_album(&albums[0], "Master of Puppets", "Metallica", 1986);
    init_album(&albums[1], "Black Album", "Metallica", 1991);

    printf("Tableau initial (%d albums):\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        print_album(&albums[i]);
    }

    int new_size = 4;
    struct album *new_albums = realloc_album(albums, initial_size, new_size);
    if (new_albums == NULL) {
        fprintf(stderr, "Error while resizing the array...\n");

        for (int i = 0; i < initial_size; i++) {
            free_album_contents(&albums[i]);
        }
        free(albums);
        return 1;
    }

    albums = new_albums;

    init_album(&albums[2], "Ride the Lightning", "Metallica", 1984);
    init_album(&albums[3], "...And Justice for All", "Metallica", 1988);

    printf("\nNew albums (%d albums):\n", new_size);
    for (int i = 0; i < new_size; i++) {
        print_album(&albums[i]);
    }

    for (int i = 0; i < new_size; i++) {
        free_album_contents(&albums[i]);
    }
    free(albums);

    return 0;
}
