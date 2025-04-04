#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s) {
    int i = 0;
    while (s[i]) i++;
    return i;
}

char *ft_strdup(char *src) {
    int len = ft_strlen(src);
    char *copy = malloc(len + 1);
    if (!copy) return NULL;
    for (int i = 0; i < len; i++) copy[i] = src[i];
    copy[len] = '\0';
    return copy;
}

int ft_strcmp(char *a, char *b) {
    while (*a && *a == *b) { a++; b++; }
    return *(unsigned char *)a - *(unsigned char *)b;
}

char *ft_substr(char *src, int start, int end) {
    int len = end - start;
    char *sub = malloc(len + 1);
    if (!sub) return NULL;
    for (int i = 0; i < len; i++) sub[i] = src[start + i];
    sub[len] = '\0';
    return sub;
}

void print_error(char *msg) {
    while (*msg)
        write(2, msg++, 1);
    write(2, "\n", 1);
}
