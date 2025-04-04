#ifndef MUSIC_H
#define MUSIC_H

typedef struct s_song {
    char *artist;
    char *title;
    int year;
    struct s_song *next;
} t_song;

/* Functions prototypes */

// list.c
t_song *parse_line(char *line);
void append_song(t_song **head, t_song *new);
void free_list(t_song *head);

// parser.c
int read_file(const char *filename, char *buffer, int size);
int is_valid_sort(char *str);

// utils.c
int ft_strlen(char *s);
char *ft_strdup(char *src);
int ft_strcmp(char *a, char *b);
char *ft_substr(char *src, int start, int end);

// display.c
void display_list(t_song *head);
void sort_list(t_song *head, char *key);

// common
void print_error(char *msg);

#endif
