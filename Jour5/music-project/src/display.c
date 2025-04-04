#include "music.h"
#include <unistd.h>

void display_list(t_song *head) {
    while (head) {
        write(1, "\"", 1);
        write(1, head->title, ft_strlen(head->title));
        write(1, "\" by \"", 6);
        write(1, head->artist, ft_strlen(head->artist));
        write(1, "\" released in ", 15);

        char year[5];
        int y = head->year;
        for (int i = 3; i >= 0; i--) {
            year[i] = '0' + (y % 10);
            y /= 10;
        }
        write(1, year, 4);
        write(1, ".\n", 2);
        head = head->next;
    }
}

void swap(t_song *a, t_song *b) {
    char *tmp_artist = a->artist;
    char *tmp_title = a->title;
    int tmp_year = a->year;

    a->artist = b->artist;
    a->title = b->title;
    a->year = b->year;

    b->artist = tmp_artist;
    b->title = tmp_title;
    b->year = tmp_year;
}

void sort_list(t_song *head, char *key) {
    for (t_song *i = head; i && i->next; i = i->next) {
        for (t_song *j = i->next; j; j = j->next) {
            int cmp = 0;
            if (key[0] == 'a') cmp = ft_strcmp(i->artist, j->artist);
            else if (key[0] == 't') cmp = ft_strcmp(i->title, j->title);
            else if (key[0] == 'y') cmp = i->year - j->year;
            if (cmp > 0)
                swap(i, j);
        }
    }
}
