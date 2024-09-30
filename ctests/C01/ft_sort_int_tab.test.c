#include "../../cmd/cfiles/ft_sort_int_tab.c"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test1(void);
int test2(void);
int test3(void);
int test4(void);
int test5(void);

int main(void) {
  if ((test1() + test2() + test3() + test4() + test5()) != 0)
    return (1);
  return (0);
}

// Tests
int test1(void) {
  int tab[6] = {7, 6, 3, 4, 2, 5};
  int size = 6;

  ft_sort_int_tab(tab, size);

  if (tab[0] != 2 || tab[1] != 3 || tab[2] != 4 || tab[3] != 5 || tab[4] != 6 ||
      tab[5] != 7) {
    printf(":( | [1] Failed to sort tab.\nGot :");
    printf("Actual value: tab = {7, 6, 3, 4, 2, 5}\n");
    printf("Got: tab = {%d, %d, %d, %d, %d, %d}\n", tab[0], tab[1], tab[2],
           tab[3], tab[4], tab[5]);
    printf("Expected: tab = {2, 3, 4, 5, 6, 7}\n");
    return (1);
  }
  printf(":) | [1] Successfully sorted tab.\n");
  printf("Actual value: tab = {7, 6, 3, 4, 2, 5}\n");
  printf("Got: tab = {7, 6, 3, 4, 2, 5}\n");
  return (0);
}

int test2(void) {
  int tab[4] = {1, 3, 3, 7};
  int size = 4;

  ft_sort_int_tab(tab, size);

  if (tab[0] != 1 || tab[1] != tab[2] || tab[3] != 7) {
    printf(":( | [2] Failed to sort tab.\nGot :");
    printf("Actual value: tab = {1, 3, 3, 7}\n");
    printf("Got: tab = {%d, %d, %d, %d}\n", tab[0], tab[1], tab[2], tab[3]);
    printf("Expected: tab = {1, 3, 3, 7}\n");
    return (1);
  }
  printf(":) | [2] Successfully sorted tab.\n");
  printf("Actual value: tab = {1, 3, 3, 7}\n");
  printf("Got: tab = {1, 3, 3, 7}\n");
  return (0);
}

int test3(void) {
  int tab[4] = {7, 3, 3, 1};
  int size = 4;

  ft_sort_int_tab(tab, size);

  if (tab[0] != 1 || tab[1] != tab[2] || tab[3] != 7) {
    printf(":( | [3] Failed to sort tab.\nGot :");
    printf("Actual value: tab = {7, 3, 3, 1}\n");
    printf("Got: tab = {%d, %d, %d, %d}\n", tab[0], tab[1], tab[2], tab[3]);
    printf("Expected: tab = {1, 3, 3, 7}\n");
    return (1);
  }
  printf(":) | [3] Successfully sorted tab.\n");
  printf("Actual value: tab = {7, 3, 3, 1}\n");
  printf("Got: tab = {1, 3, 3, 7}\n");
  return (0);
}

int test4(void) {
  int tab[4] = {3, 7, 3, 1};
  int size = 4;

  ft_sort_int_tab(tab, size);

  if (tab[0] != 1 || tab[1] != tab[2] || tab[3] != 7) {
    printf(":( | [4] Failed to sort tab.\nGot :");
    printf("Actual value: tab = {3, 7, 3, 1}\n");
    printf("Got: tab = {%d, %d, %d, %d}\n", tab[0], tab[1], tab[2], tab[3]);
    printf("Expected: tab = {1, 3, 3, 7}\n");
    return (1);
  }
  printf(":) | [4] Successfully sorted tab.\n");
  printf("Actual value: tab = {3, 7, 3, 1}\n");
  printf("Got: tab = {1, 3, 3, 7}\n");
  return (0);
}

int test5(void) {
  int tab[4] = {1, 9, 4, 9};
  int size = 4;

  ft_sort_int_tab(tab, size);

  if (tab[0] != 1 || tab[1] != 4 || tab[2] != 9 || tab[3] != 9) {
    printf(":( | [5] Failed to sort tab.\nGot :");
    printf("Actual value: tab = {1, 9, 4, 9}\n");
    printf("Got: tab = {%d, %d, %d, %d}\n", tab[0], tab[1], tab[2], tab[3]);
    printf("Expected: tab = {1, 4, 9, 9}\n");
    return (1);
  }
  printf(":) | [5] Successfully sorted tab.\n");
  printf("Actual value: tab = {1, 9, 4, 9}\n");
  printf("Got: tab = {1, 4, 9, 9}\n");
  return (0);
}
