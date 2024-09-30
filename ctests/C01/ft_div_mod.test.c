#include "../../cmd/cfiles/ft_div_mod.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test1(void);
int test2(void);
int test3(void);

int main(void) {
  if (test1() + test2() + test3() != 0)
    return (1);
  return (0);
}

int test1(void) {
  int a;
  int b;
  int x;
  int y;

  a = 10;
  b = 5;
  ft_div_mod(a, b, &x, &y);

  if (x != 2 || y != 0) {
    printf(":( | [1] ft_div_mod(10, 5, &x, &y)\nExpected x = 2, y = 0 Got x = "
           "%d y = %d\n",
           x, y);
    return (1);
  }
  printf(":) | [1] ft_div_mod(10, 5, &x, &y)\nExpected x = 2, y = 0 Got x = %d "
         "y = %d\n",
         x, y);
  return (0);
}

int test2(void) {
  int a;
  int b;
  int x;
  int y;

  a = 25;
  b = 6;
  ft_div_mod(a, b, &x, &y);

  if (x != 4 || y != 1) {
    printf(
        ":( | [2] ft_div_mod(25, 6, &x, &y)\nExpected x = 4, y = 1 Got x = %d "
        "y = %d\n",
        x, y);
    return (1);
  }
  printf(":) | [2] ft_div_mod(25, 6, &x, &y)\nExpected x = 4, y = 1 Got x = %d "
         "y = %d\n",
         x, y);
  return (0);
}

int test3(void) {
  int a;
  int b;
  int x;
  int y;

  a = 47;
  b = 8;
  ft_div_mod(a, b, &x, &y);

  if (x != 5 || y != 7) {
    printf(
        ":( | [3] ft_div_mod(47, 8, &x, &y)\nExpected x = 5, y = 7 Got x = %d "
        "y = %d\n",
        x, y);
    return (1);
  }
  printf(":) | [3] ft_div_mod(47, 8, &x, &y)\nExpected x = 5, y = 7 Got x = %d "
         "y = %d\n",
         x, y);
  return (0);
}
