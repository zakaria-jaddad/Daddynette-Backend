#include "../../cmd/cfiles/ft_strlen.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_test {
  char *desc;
  char *input;
  int expected_output;
} t_test;

int run_tests(t_test *tests, int count);

int main(void) {
  t_test tests[] = {
      {
          .desc = "Empty string",
          .input = "",
          .expected_output = 0,
      },
      {
          .desc = "Single character",
          .input = "H",
          .expected_output = 1,
      },
      {
          .desc = "Long string with no null character",
          .input = "Hello, world!",
          .expected_output = 13,
      },
      {
          .desc = "Long string with null character",
          .input = "Hello\0, world!",
          .expected_output = 5,
      },
      {
          .desc = "Very long string",
          .input = "Ara Chi Bouyssa",
          .expected_output = 15,
      },
  };
  int count = sizeof(tests) / sizeof(tests[0]);

  return run_tests(tests, count);
}

int run_tests(t_test *tests, int count) {
  int i;
  int error = 0;

  for (i = 0; i < count; i++) {

    int result = ft_strlen(tests[i].input);

    // Check that the output matches the expected value
    if (result != tests[i].expected_output) {

      printf(":( | [%d] ft_strlen(\"%s\")\nExpected %d\nGot %d\n", i + 1,
             tests[i].input, tests[i].expected_output, result);
      error -= 1;
    } else {
      printf(":) | [%d] ft_strlen(\"%s\")\nAs expected %d\n", i + 1,
             tests[i].input, result);
    }
  }
  if (error != 0)
    return 1;
  return (error);
}
