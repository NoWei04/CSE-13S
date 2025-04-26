#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

// cons is the traditional name for the function that builds up a linked list,
// in languages like Lisp or Haskell, as you'll know because Alex said this a
// few times in class.
ll_int *cons(int val, ll_int *list) {
  ll_int *out = calloc(1, sizeof(ll_int));
  out->val = val;
  out->next = list;
  return out;
}

int main(void) {
  ll_int *list = NULL;
  // 10 is the biggest value and appears 3 times in this list.
  list = cons(10, cons(10, cons(9, cons(9, cons(10, cons(1, NULL))))));

  int biggest;
  size_t count = count_and_find_maximum(list, &biggest);
  should_be_exactly_equal("should have found 3 instances", 3, count);
  should_be_exactly_equal("biggest value should be 10", 10, biggest);

  return 0;
}
