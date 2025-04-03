#ifndef ALBUM_H
#define ALBUM_H

struct album {
    char *title;
    char *artiste;
    int year;
    struct album *next; 
};

// Prototypes des fonctions
struct album *create_album(const char *title, const char *artist, int year);
void print_album(const struct album *a);
void free_album(struct album *a);
void push_back_album(struct album **head, struct album *new_album);
void push_front_album(struct album **head, struct album *new_album);
void album_del_one(struct album **head, struct album *to_delete); 
void sort_album_by(struct album *head);


#endif /* ALBUM_H */
