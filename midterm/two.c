#include "midterm.h"

#include <stdio.h>

ll_float *insert_increasing_order(ll_float *list, float val) {
  ll_float *node = malloc(sizeof(ll_float));
  ll_float *i = list;
  node -> value = val;
  node -> next = NULL;
  
  if(list == NULL || list -> value > val){
     node -> next = list;
     return node;}
  
  while(i -> next != NULL && i -> next -> value < val){
     i = i -> next;}

  node -> next = i -> next;
  i -> next = node;
  return list;
}
