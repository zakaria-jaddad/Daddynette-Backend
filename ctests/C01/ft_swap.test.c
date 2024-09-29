#include "../../cmd/cfiles/ft_swap.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_test {
  char *desc;
  int x;
  int y;
  int expected_x;
  int expected_y;
} t_test;

int run_tests(t_test *tests, int count);

int main(void) {
  t_test tests[] = {
      {
          .desc = "Swap two positive integers",
          .x = 2,
          .y = 3,
          .expected_x = 3,
          .expected_y = 2,
      },
      {
          .desc = "Swap a positive and negative integer",
          .x = 9,
          .y = -4,
          .expected_x = -4,
          .expected_y = 9,
      },
      {
          .desc = "Swap two negative integers",
          .x = -32,
          .y = 54,
          .expected_x = 54,
          .expected_y = -32,
      },
      {
          .desc = "Swap numbers that may exceed INT_MAX if added",
          .x = 4576878,
          .y = 4576878,
          .expected_x = 4576878,
          .expected_y = 4576878,
      },
  };
  int count = sizeof(tests) / sizeof(tests[0]);

  return run_tests(tests, count);
}

int run_tests(t_test *tests, int count) {
  int i;
  int error = 0;

  for (i = 0; i < count; i++) {
    int x = tests[i].x;
    int y = tests[i].y;

    ft_swap(&x, &y);

    /* // Check that the output matches the expected value */
    /* if (strcmp(buffer, tests[i].expected) != 0) { */
    /*   printf(":( | [%d] %s \nkExpected \"%s\" \nGot \"%s\"\n", i + 1, */
    /*          tests[i].desc, tests[i].expected, buffer); */
    /*   error -= 1; */
    /* } else { */
    /*   printf(":) | [%d] %s \nOutput \"%s\" \nAs expected\n", i + 1, */
    /*          tests[i].desc, buffer); */
    /* } */

    if (x != tests[i].expected_x || y != tests[i].expected_y) {
      printf(":( | [%d] %s Expected x = %d, y = %d, Got x = %d, y = %d\n",
             i + 1, tests[i].desc, tests[i].expected_x, tests[i].expected_y, x,
             y);
      error--;
    } else {
      printf(":) | [%d] %s Passed\n", i + 1, tests[i].desc);
    }
  }

  if (error != 0)
    return 1;
  return (error);
}
