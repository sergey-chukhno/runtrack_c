
#include <stdlib.h>
#include <unistd.h>

// Function conveting to lowercase
void to_lowercase(char *str) {
    if (str == NULL) {
      return;
    }
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Converting uppercase to lowercase
        }
        i++;
    }
}


// Function to write character in standard output
void write_string(const char *str) {
    if (str == NULL) {
      return;
    }
    
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    
    write(STDOUT_FILENO, str, i);
    write(STDOUT_FILENO, "\n", 1);
}


int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        return 0;
    }
    
  
    for (int i = 1; i < argc; i++) {
        int length = 0;
        char *arg = argv[i];
        
        while (arg[length] != '\0') {
            length++;
        }
        
        char *copy = (char *)malloc((length + 1) * sizeof(char));
        if (copy == NULL) {
            continue;
        }
        
        for (int j = 0; j <= length; j++) {
            copy[j] = arg[j];
        }
        
        // Converting to lowercase
        to_lowercase(copy);
        
        // Printing in standard output
        write_string(copy);
        
        // Freeing memory
        free(copy);
    }
    
    return 0;
}