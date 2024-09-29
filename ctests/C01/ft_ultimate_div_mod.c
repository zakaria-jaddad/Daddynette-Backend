#include "../../cmd/cfiles/ft_ultimate_div_mod.c"
#include "../../../utils/constants.h"
#include <fcntl.h>
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
  int x;
  int y;

  x = 15;
  y = 3;
  ft_ultimate_div_mod(&x, &y);

  if (x != 5 || y != 0) {
    printf(":( | [1] ft_ultimate_div_mod(x = 15, y = 3)\nExpected x = 5,"
           "Got %d. Expected y = 0, Got %d\n",
           x, y);
    return (1);
  }
  printf(":) | [1] ft_ultimate_div_mod(x = 15, y = 3)\nExpected x = 5, Got %d. "
         "= 0, Got %d\n",
         x, y);
  return (0);
}

int test2(void) {
  int x;
  int y;

  x = 23;
  y = 5;
  ft_ultimate_div_mod(&x, &y);

  if (x != 4 || y != 3) {
    printf(":( | [2] ft_ultimate_div_mod(x = 23, y = 5) Expected x = 4,"
           "Got %d. Expected y = 3, Got %d\n",
           x, y);
    return (1);
  }

  printf(":) | [2] ft_ultimate_div_mod(x = 23, y = 5)\nExpected x = 4, Got %d. "
         "Expected y = 3, got %d\n",
         x, y);
  return (0);
}

int test3(void) {
  int x;
  int y;

  x = 32;
  y = 5;
  ft_ultimate_div_mod(&x, &y);

  if (x != 6 || y != 2) {
    printf(":( | [3] ft_ultimate_div_mod(x = 32, y = 5) Expected x = 6,"
           "Got %d. Expected y = 2, Got %d\n",
           x, y);
    return (1);
  }
  printf(":) | [3] ft_ultimate_div_mod(x = 32, y = 5)\nExpected x = 6, Got %d. "
         "Expected y = 2, got %d\n",
         x, y);
  return (0);
}
