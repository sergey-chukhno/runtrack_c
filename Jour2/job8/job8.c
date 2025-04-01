
#include <stdlib.h>
#include <unistd.h>

// Function to find str length
int str_len(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

//Function to compare strings value (ASCII)
int str_cmp(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
        i++;
    }
    return a[i] - b[i];
}

//Function to trim 
char *trim_str(const char *str) {
    if (str == NULL) return NULL;
    
    int len = str_len(str);
    
    // Finding the first character which is not a space
    int start = 0;
    while (start < len && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')) {
        start++;
    }
    
    // Finding the last character that is not a space
    int end = len - 1;
    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }
    
    // Checking if the chain of characters is empty or contains only spaces
    if (start > end) {
        char *result = (char *) malloc(1);
        if (result != NULL) {
            result[0] = '\0';
        }
        return result;
    }
    
    // Allocating memory for the result
    int new_len = end - start + 1;
    char *result = (char *) malloc(new_len + 1);
    if (result == NULL) return NULL;
    
    // Copying characters that are not spaces
    for (int i = 0; i < new_len; i++) {
        result[i] = str[start + i];
    }
    result[new_len] = '\0';
    
    return result;
}

//Sorting characteris
void sort_strings(char **strs, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (str_cmp(strs[j], strs[j + 1]) > 0) {
                // swap pointers
                char *temp = strs[j];
                strs[j] = strs[j + 1];
                strs[j + 1] = temp;
            }
        }
    }
}

//Writing characters in standard output
void write_string(const char *str) {
    write(STDOUT_FILENO, str, str_len(str));
}

int main(int argc, char *argv[]) {
    // If no argument is given
    if (argc < 2) {
        write_string("\n");
        return 0;
    }
    
    // Allocating memory 
    char **trimmed_strs = (char **) malloc((argc - 1) * sizeof(char *));
    if (trimmed_strs == NULL) {
        return 1;
    }
    
    // Trimming each character
    for (int i = 1; i < argc; i++) {
        trimmed_strs[i - 1] = trim_str(argv[i]);
        if (trimmed_strs[i - 1] == NULL) {
            for (int j = 0; j < i - 1; j++) {
                free(trimmed_strs[j]);
            }
            free(trimmed_strs);
            return 1;
        }
    }
    
    //Sorting characters
    sort_strings(trimmed_strs, argc - 1);
    
    // Displaying sorted strings
    for (int i = 0; i < argc - 1; i++) {
        write_string(trimmed_strs[i]);
        if (i < argc - 2) {
            write_string(" ");
        }
    }
    
    // Adding new line
    write_string("\n");
    
    // Freeing memory
    for (int i = 0; i < argc - 1; i++) {
        free(trimmed_strs[i]);
    }
    free(trimmed_strs);
    
    return 0;
}