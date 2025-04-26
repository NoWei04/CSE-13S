#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, size_t expected,
                             size_t actual) {
  printf("%s\n", message);
  printf("%s: wanted %lu, got %lu\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {

  int **matrix1;
  matrix1 = calloc(3, sizeof(int *));
  for (int i = 0; i < 3; i++) {
    // now allocate each individual row, filled with 0 initially.
    matrix1[i] = calloc(3, sizeof(int));
  }
  // make the 0th and 2th rows have a larger values in them their 0th columns
  matrix1[0][0] = 20;
  matrix1[2][0] = 30;

  // so the one with the lowest sum should be row 1
  should_be_exactly_equal("row 1 should have lowest sum", 1,
                          row_index_with_lowest_sum(matrix1, 3, 3));

  // example from the README: lowest sum is the last row, with -86
  // 0  0 0 10 0
  // 15 0 0 0  0
  // 10 0 0 10 0
  // 1  1 1 1  -90
  int **matrix2;
  matrix2 = calloc(4, sizeof(int *));
  for (int i = 0; i < 4; i++) {
    // now allocate each individual row, filled with 0 initially.
    matrix2[i] = calloc(5, sizeof(int));
  }
  matrix2[0][3] = 10;
  matrix2[1][0] = 15;
  matrix2[2][0] = 10;
  matrix2[2][4] = 10;
  matrix2[3][0] = 1;
  matrix2[3][1] = 1;
  matrix2[3][2] = 1;
  matrix2[3][3] = 1;
  matrix2[3][4] = -90;
  should_be_exactly_equal("row 3 should have lowest sum", 3,
                          row_index_with_lowest_sum(matrix2, 4, 5));

  return 0;
}
