#include "music.h"
#include <fcntl.h>
#include <unistd.h>

int read_file(const char *filename, char *buffer, int size) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1;
    int bytes = read(fd, buffer, size - 1);
    close(fd);
    return bytes;
}

int is_valid_sort(char *str) {
    return (str[0] == 'a' || str[0] == 't' || str[0] == 'y');
}
