#include "../../cmd/cfiles/ft_print_alphabet.c"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int test1(void);

int main(void) { return test1(); }

int test1(void) {
  // Redirect the output to a file
  int saved_stdout = dup(STDOUT_FILENO);
  int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  dup2(output_fd, STDOUT_FILENO);
  close(output_fd);

  // Call the function to be tested
  ft_print_alphabet();

  // Restore the original output
  fflush(stdout);
  dup2(saved_stdout, STDOUT_FILENO);
  close(saved_stdout);

  // Open the output file and check its contents
  FILE *fp = fopen("output.txt", "r");
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);
  fclose(fp);

  // Check that the output matches the expected value
  const char *expected_output = "abcdefghijklmnopqrstuvwxyz";
  if (strcmp(buffer, expected_output) != 0) {
    printf(":( | [1] ft_print_alphabet() \nExpected \"%s\" \nGot \"%s\"\n",
           expected_output, buffer);
    remove("output.txt");
    return 1;
  }
  printf(":) | [1] ft_print_alphabet() \nOutput \"%s\" \nAs expected\n",
         buffer);
  remove("output.txt");
  return 0;
}
