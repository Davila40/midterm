#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct point point;
struct point {double x, y; };
point* point_init(double a, double b) {
  point* pt = (point*)malloc(sizeof(point));
  pt->x = a;
  pt->y = b;
  return pt;
}


typedef struct square square;
struct square {point ul; double side;};
square* square_init(double ulx, double uly, double side) {
  square* sq = (square*)malloc(sizeof(square));
  sq->ul = *(point_init(ulx, uly));
  sq->side = side;
}

void square_delete(square* sq) {
  free(sq);
}

void square_move(square* sq, double x, double y) {
  sq->ul.x = x;
  sq->ul.y = y;
}

void square_expandby(square* sq, double expandby) {
  sq->side *= expandby;
}

double square_area(square* sq) {
  return (sq->side * sq->side);
}

double square_perimeter(square* r) {
  return (r->side * 4);
}

void square_print(const char* msg, square* sq) {
  printf("%s", msg);
  printf("location: %f, %f side: %f area: %f perimeter: %f", sq->ul.x, sq->ul.y, sq->side, square_area(sq), square_perimeter(sq));
}

void test_square(double ulx, double uly, double side) {
  square* sq = square_init(ulx, uly, side);
  square_print("square is: ", sq);
  square_move(sq, 2, 2);
  square_print("sq is now: ", sq);
  square_expandby(sq, 10);
  square_print("sq has been expanded to: ", sq);
  square_delete(sq);
  printf("\n\n");
}
void tests_square() {
  test_square(0, 0, 10);
  test_square(1, 1, 5);
}
int main(int argc, const char* argv[]) {
  tests_square();
  return 0;
}
