
#include <unistd.h>
#include "char_is_digit.h"

int char_is_digit(char c) { 
  if (c>='0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

// int main() {
//   char testChar = '1';
//   if (char_is_digit(testChar)) {
//     write(1, "Character is a digit.\n", 22);
//   } else {
//     write(1, "Character is not a digit\n", 26);
//   }

//   return 0;
// }