#include <stdlib.h>
#include <stdio.h>

// Function to convert an int into char using hexadecimals (capital letters) 
char *itoa_hex(int n) {
    // in case the integer is 0, we allocate memroy for '0' and '\0'
    if (n == 0) {
        char *str = (char *)malloc(2 * sizeof(char));  
        if (str == NULL) return NULL; 
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // Find length of chars
    int temp = n;
    int len = 0;
    while (temp != 0) {
        temp /= 16;
        len++;
    }

    // Memory allocation for hexadecimals + 1 for '\0' 
    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL) return NULL; //

    str[len] = '\0'; // Adding '\0' in the end of chars

    // Creating chain of hexadecimal chars
    int i = len - 1;
    while (n != 0) {
        int rem = n % 16; // Characters from '0' to '9' + from 'A' to 'F'
        if (rem < 10) {
            str[i] = rem + '0'; 
        } else {
            str[i] = rem - 10 + 'A'; 
        }
        n /= 16;
        i--;
    }

    return str;
}


int main() {
    int num = 1234567890;
    char *hex_str = itoa_hex(num);
    if (hex_str != NULL) {
        printf("Hexadecimal: %s\n", hex_str);
        free(hex_str); 
    }
    return 0;
}
