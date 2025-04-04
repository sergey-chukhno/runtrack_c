#include "includes/music.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3)
        return (print_error("Incorrect format."), 1);
    if (!is_valid_sort(argv[2]))
        return (print_error("Sort method does not exist."), 1);

    char buffer[BUFFER_SIZE];
    int bytes = read_file(argv[1], buffer, BUFFER_SIZE);
    if (bytes <= 0)
        return (print_error("File not found."), 1);
    buffer[bytes] = '\0';

    t_song *list = NULL;
    char *line = buffer;
    while (*line) {
        char *next = line;
        while (*next && *next != '\n') next++;
        if (*next == '\n') *next++ = '\0';
        t_song *song = parse_line(line);
        if (!song)
            return (free_list(list), print_error("Incorrect format."), 1);
        append_song(&list, song);
        line = next;
    }

    sort_list(list, argv[2]);
    display_list(list);
    free_list(list);
    return 0;
}
