#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases!
  // score letter
  printf("\n**** tests for score_letter ****\n");
  should_be_exactly_equal("score_letter: count of words containing 'i'", 3, score_letter('a', vocabulary, num_words)); 
  should_be_exactly_equal("score_letter: count of words containing 's'", 4, score_letter('s', vocabulary, num_words)); 

  // score word
  printf("\n**** tests for score_word ****\n");
  int letter_scores[26];
  for (int i = 0; i < 26; i++){
    letter_scores[i] = i;}

  should_be_exactly_equal("score_word: score of 'scrap'", 18 + 2 + 17 + 0 + 15, score_word("scrap", letter_scores));
  should_be_exactly_equal("score_word: score of 'shear'", 18 + 7 + 4 + 0 + 17, score_word("shear", letter_scores));

  // filter grey
  printf("\n**** tests for filter_vocabulary_gray ****\n");
  size_t filtered_gray_count = filter_vocabulary_gray('i', vocabulary, num_words);

  should_be_exactly_equal("filter_vocabulary_gray: filtered count (without 'i')", 3, filtered_gray_count);

  // filter yellow
  printf("\n**** tests for filter_vocabulary_yellow ****\n");
  size_t filtered_yellow_count = filter_vocabulary_yellow('i', 1, vocabulary, num_words);

  should_be_exactly_equal("filter_vocabulary_yellow: filtered count ('i' not at pos 2)", 2, filtered_yellow_count);

  // filter green
  printf("\n**** tests for filter_vocabulary_green ****\n");
  size_t filtered_green_count = filter_vocabulary_green('i', 2, vocabulary, num_words);

  should_be_exactly_equal("filter_vocabulary_green: filtered count ('i' at pos 2)", 9, filtered_green_count);

  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}

