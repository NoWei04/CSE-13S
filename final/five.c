#include "final.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WordCountTree* insert_tree(WordCountTree *tree, const char *word, int count) {
    if (tree == NULL) {
        tree = (WordCountTree*)malloc(sizeof(WordCountTree));
        tree->word = strdup(word);
        tree->count = count;
        tree->left = tree->right = NULL;
        return tree;}

    int compare_words = strcmp(word, tree->word);

    if (compare_words < 0) {
        tree->left = insert_tree(tree->left, word, count);}
    else if (compare_words > 0) {
        tree->right = insert_tree(tree->right, word, count);}
    else {
        tree->count += count;}
    return tree;}

void merge_traverse(WordCountTree *tree, WordCountTree **result_tree) {

    if (tree == NULL){
       return;}

    merge_traverse(tree->left, result_tree);
    *result_tree = insert_tree(*result_tree, tree->word, tree->count);
    merge_traverse(tree->right, result_tree);}

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {

    WordCountTree *result_tree = NULL;
    merge_traverse(tree1, &result_tree);
    merge_traverse(tree2, &result_tree);
    return result_tree;}

