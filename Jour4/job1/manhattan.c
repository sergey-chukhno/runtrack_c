#include "manhattan.h"
#include <stdio.h>

int manhattan(point p1, point p2) {
  int dx = ABS(p1.x - p2.x);
  int dy = ABS(p1.y - p2.y); 

  //The Manhattan distance is the sum of absolute distances
  //on each dimension (x and y)
  return dx + dy; 
}

int main() {
  point p1 = {2, 3};
  point p2 = {-3, 4};

  int distance = manhattan(p1, p2);

  printf("The distance between point p1 (%d, %d) and point p2 (%d, %d) = %d\n", p1.x, p1.y, p2.x, p2.y, distance);

  return 0;
}