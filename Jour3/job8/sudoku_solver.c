#include <stdio.h>
#include <unistd.h>

int is_valid(int grid[9][9], int row, int col, int num) {
  for (int c = 0; c < 9; c++) {
      if (grid[row][c] == num) {
          return 0;
      }
  }
  for (int r = 0; r < 9; r++) {
      if (grid[r][col] == num) {
          return 0;
      }
  }
  int start_row = (row / 3) * 3;
  int start_col = (col / 3) * 3;
  for (int r = start_row; r < start_row + 3; r++) {
      for (int c = start_col; c < start_col + 3; c++) {
          if (grid[r][c] == num) {
              return 0;
          }
      }
  }
  return 1;
}

int find_empty_cell(int grid[9][9], int *row, int *col) {
  for (*row = 0; *row < 9; (*row)++) {
      for (*col = 0; *col < 9; (*col)++) {
          if (grid[*row][*col] == 0) {
              return 1;
          }
      }
  }
  return 0;
}

int is_valid_grid(int grid[9][9]) {
  for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
          int num = grid[row][col];
          if (num != 0) {
              for (int c = 0; c < 9; c++) {
                  if (c != col && grid[row][c] == num) {
                      return 0;
                  }
              }
              for (int r = 0; r < 9; r++) {
                  if (r != row && grid[r][col] == num) {
                      return 0;
                  }
              }
              int start_row = (row / 3) * 3;
              int start_col = (col / 3) * 3;
              for (int r = start_row; r < start_row + 3; r++) {
                  for (int c = start_col; c < start_col + 3; c++) {
                      if ((r != row || c != col) && grid[r][c] == num) {
                          return 0;
                      }
                  }
              }
          }
      }
  }
  return 1;
}

int sudoku_solver(int grid[9][9]) {
  if (!is_valid_grid(grid)) {
      return 0;
  }
  int row, col;
  if (!find_empty_cell(grid, &row, &col)) {
      return 1;
  }
  for (int num = 1; num <= 9; num++) {
      if (is_valid(grid, row, col, num)) {
          grid[row][col] = num;
          if (sudoku_solver(grid)) {
              return 1;
          }
          grid[row][col] = 0;
      }
  }
  return 0;
}

int main() {
  // Sample of Sudoku grid (0 represents empty cells)
  int grid[9][9] = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0},
      {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0},
      {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1},
      {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0},
      {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  if (sudoku_solver(grid)) {
      printf("Solution found:\n");
      for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
              printf("%d ", grid[i][j]);
          }
          printf("\n");
      }
  } else {
      printf("No solution exists.\n");
  }
  return 0;
}