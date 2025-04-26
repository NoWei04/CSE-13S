#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
  int val_depth;

  if(tree == NULL){
     return -1;}
  if(tree -> val == value){
     return 0;}

  int search_left = depth_of_value(value, tree->left);
  int search_right = depth_of_value(value, tree->right);

  if(search_left == -1 && search_right == -1){
     return -1;}

  if(search_left == -1){
     return search_right + 1;}
  if(search_right == -1){
     return search_left + 1;}

  if(search_left < search_right){
     val_depth = search_left;}
  else{
     val_depth = search_right;}

  return val_depth + 1;
}
