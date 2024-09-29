#include "../../cmd/cfiles/ft_ft.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int test1(void);

int main(void) { return (test1()); }

int test1(void) {
  int *nbr;
  int number;
  int expected_output;

  number = 33;
  nbr = &number;
  ft_ft(nbr);
  expected_output = 42;
  if (number != expected_output) {
    printf("(: | [1] ft_ft() Expected %d, Got %d\n", expected_output, number);
    return (1);
  }
  printf(":) | [1] ft_ft() Expected %d, Got %d\n", expected_output, number);
  return (0);
}
