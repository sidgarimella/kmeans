#include <stdio.h>

#include <kmeans.h>
#include <parallel_distance.h>

int main() {
  Point a = {.x_ = 0, .y_ = 0};
  Point b = {.x_ = 0, .y_ = 34};
  Point c = {.x_ = 0, .y_ = 20};
  Point d = {.x_ = 0, .y_ = 3};
  Point e = {.x_ = 0, .y_ = 4};
  Point f = {.x_ = 0, .y_ = 19};
  Point g = {.x_ = 0, .y_ = 18};
  Point h = {.x_ = 0, .y_ = 7};
  Point i = {.x_ = 0, .y_ = 8};

  Point o = {.x_ = 0, .y_ = 0};
  Point m = {.x_ = 0, .y_ = 4};

  Point z[] = {a, b, c, d, e, f, g, h, i};
  double w[9];
  printf("Distance: %f\n", distanceSquared(a, b));
  distanceSquareds(o, z, 9, w);
  for (int i = 0; i < 9; ++i)
    printf("%d: %f\n", i, w[i]);
  printf("nthreads: %d\n", NTHREADS);

  Point centers[] = {o, m};

  Point *centers2 = kmeans(z, 9, 2);

  for (int i = 0; i < 2; ++i)
    printf("Final center %d: %f, %f\n", i, centers2[i].x_, centers2[i].y_);
}
