#include <stdio.h>
#include <string.h> 

int my_atoi(char *str) {
  int result = 0;
  int i = 0; 

  //Handling empyt spaces 
  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
    i++;
  
  while (str[i] >= '0' && str[i] <=9) {
    result = result * 10 + (str[i] - '0'); /* '(str[i] -'0') converts character into its numeric value (the corresponding numeric values ('0' to '9') have consecutive ASCII values - for example, '0' has the ASCII value of 48, '1' has the ASCII value of 49, etc. If we substract '0' (48) from num's ASCII value, we get its numeric value (for example, for '2', we do '50-48', etc)). 
    We then do 'result * 10' to make room for a new numeric value (for instance, if we have '123', we need first to transfomr '12' into 120 before adding '3')
    */
  }
  return result;
}