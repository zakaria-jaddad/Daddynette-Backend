#include "../../cmd/cfiles/ft_rev_int_tab.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test1(void);
int test2(void);

int main(void) {
  if (test1() + test2() != 0)
    return (-1);
  return (0);
}

int test1(void) {
  int tab[6] = {0, 1, 2, 4, 3, 5};
  int size = 6;

  ft_rev_int_tab(tab, size);

  if (tab[0] != 5 || tab[1] != 3 || tab[2] != 4 || tab[3] != 2 || tab[4] != 1 ||
      tab[5] != 0) {
    printf(":( | [1] Failed to reverse tab.\n Got:");
    printf("Actual value: tab = {0, 1, 2, 4, 3, 5}\n");
    printf("Got: tab = {%d, %d, %d, %d, %d, %d}\n", tab[0], tab[1], tab[2],
           tab[3], tab[4], tab[5]);
    printf("Expected: tab = {5, 3, 4, 2, 1, 0}\n");
    return (1);
  }
  printf(":) | [1] Tab successfully reversed\n");
  printf("Actual value: tab = {0, 1, 2, 4, 3, 5}\n");
  printf("Got: tab = {5, 3, 4, 2, 1, 0}\n");
  return (0);
}

int test2(void) {
  int tab[6] = {9, 4, 9, 1};
  int size = 4;

  ft_rev_int_tab(tab, size);

  if (tab[0] != 1 || tab[1] != 9 || tab[2] != 4 || tab[3] != 9) {
    printf(":( | [2] Failed to reverse tab.\n Got:");
    printf("Actual value: tab = {9, 4, 9, 1}\n");
    printf("Got: tab = {%d, %d, %d, %d}\n", tab[0], tab[1], tab[2], tab[3]);
    printf("Expected: tab = {1, 9, 4, 9}");
    return (1);
  }
  printf(":) | [2] Tab successfully reversed\n");
  printf("Actual value: tab = {0, 1, 2, 4, 3, 5}\n");
  printf("Got: tab = {5, 3, 4, 2, 1, 0}\n");
  return (0);
}
