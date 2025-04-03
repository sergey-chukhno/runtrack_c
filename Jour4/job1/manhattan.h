#ifndef MANHATTAN_H
#define MANHATTAN_H

typedef struct {
  int x;
  int y;
} point; 

/* Macros to calculate an absolute value of a number*/
#define ABS(x) ((x)<0 ? - (x):(x))

/* Prototype of Manhattan function*/
int manhattan(point p1, point p2);

#endif /* MANHATTAN_H */