#include "final.h"

#include <stdio.h>
#include <stdlib.h>

BinaryTree *build_tree(int value, BinaryTree *left, BinaryTree *right) {
  BinaryTree *out = calloc(1, sizeof(BinaryTree));
  out->val = value;
  out->left = left;
  out->right = right;

  return out;
}

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  BinaryTree *tree =
      build_tree(14, build_tree(3, NULL, NULL),
                 build_tree(15, NULL, build_tree(42, NULL, NULL)));

  // Here we should find 42 at depth 2 (path is 14->15->42)
  should_be_exactly_equal("value 42 at depth 2", 2, depth_of_value(42, tree));

  should_be_exactly_equal("value -15 should not be found", -1,
                          depth_of_value(-15, tree));

  return 0;
}
