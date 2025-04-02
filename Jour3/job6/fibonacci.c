#include <unistd.h>

// Function to convert an integer into char and print it

void ft_putnbr(int n) {
  char c; 
  if (n>=10)
    ft_putnbr(n / 10);
  c = (n % 10) + '0';
  write(1, &c, 1); 
}

int fibonacci(int n) {
  if (n <= 0)
    return 0; 
  if (n == 1)
    return 1;

  int a = 0, b = 1, temp;
  for (int i = 2; i <= n; i++) {
    temp = a + b;
    a = b;
    b = temp; 
  }
  return b; 
}

int main(int argc, char* argv[]) {
  if (argc != 2)
    return 0; // Return nothing if no arguments are given

  int num = 0;
  for (int i = 0; argv[1][i] >= '0' && argv[1][i] <= '9'; i++) {
    num = num * 10 + (argv[1][i] - '0');
  }
  int result = fibonacci(num);
  ft_putnbr(result);
  write(1, "\n", 1);

  return 0;
}