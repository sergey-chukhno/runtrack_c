#include "music.h"
#include <stdlib.h>

t_song *parse_line(char *line) {
    int i = 0, j = 0;
    while (line[i] && line[i] != ',') i++;
    if (!line[i]) return NULL;
    char *artist = ft_substr(line, 0, i);
    j = ++i;
    while (line[i] && line[i] != ',') i++;
    if (!line[i]) return NULL;
    char *title = ft_substr(line, j, i);
    char *year_str = ft_substr(line, ++i, ft_strlen(line));
    int year = atoi(year_str);
    free(year_str);

    t_song *song = malloc(sizeof(t_song));
    if (!song) return NULL;
    song->artist = artist;
    song->title = title;
    song->year = year;
    song->next = NULL;
    return song;
}

void append_song(t_song **head, t_song *new) {
    if (!*head) {
        *head = new;
        return;
    }
    t_song *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

void free_list(t_song *head) {
    t_song *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp->artist);
        free(tmp->title);
        free(tmp);
    }
}
