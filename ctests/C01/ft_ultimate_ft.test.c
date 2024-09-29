#include "../../cmd/cfiles/ft_ultimate_ft.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test1(void);

int main(void) { return test1(); }

int test1(void) {
  int number;
  int *nbr8;
  int **nbr7;
  int ***nbr6;
  int ****nbr5;
  int *****nbr4;
  int ******nbr3;
  int *******nbr2;
  int ********nbr1;
  int *********nbr;
  int expected_output;

  number = 21;

  nbr8 = &number;
  nbr7 = &nbr8;
  nbr6 = &nbr7;
  nbr5 = &nbr6;
  nbr4 = &nbr5;
  nbr3 = &nbr4;
  nbr2 = &nbr3;
  nbr1 = &nbr2;
  nbr = &nbr1;

  ft_ultimate_ft(nbr);
  expected_output = 42;

  if (number != expected_output) {
    printf("(: | [1] ft_ultimate_ft() Expected %d, Got %d\n", expected_output,
           number);
    return (1);
  }
  printf(":) | [1] ft_ultimate_ft() Expected %d, Got %d\n", expected_output,
         number);
  return (0);
}
