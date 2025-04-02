#include <unistd.h>

// Function to convert an integer into char and print it

void ft_putnbr(int n) {
  char c; 
  if (n>=10)
    ft_putnbr(n / 10);
  c = (n % 10) + '0';
  write(1, &c, 1); 
}

// Function to calculate factorial 
int factorial(int n) {
  if (n < 0)
    return 0; // No factorial for negative numbers;
  if (n == 0 || n == 1)
    return 1;

  return n * factorial(n - 1); // Using recursion to calculate the factorial of n
}

int main(int argc, char* argv[]) {
  if (argc != 2)
    return 0; // Return nothing if no arguments are given

  int num = 0;
  for (int i = 0; argv[1][i] >= '0' && argv[1][1] <= '9'; i++) {
    num = num * 10 + (argv[1][i] - '0');
  }
  int result = factorial(num);
  ft_putnbr(result);
  write(1, "\n", 1);

  return 0;
}
