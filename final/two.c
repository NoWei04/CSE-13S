#include "final.h"

#include <stdio.h>

size_t count_and_find_maximum(ll_int *list, int *maxval) {
  size_t count = 0;
  int greatest = 0;
  
  if(list != NULL){
     greatest = list -> val;}
  else{
     greatest = 0;}
  
  for(ll_int *current = list; current != NULL; current = current -> next){
     if(current -> val > greatest){
        greatest = current -> val;
        count = 1;}
     else if(current -> val == greatest){
        count ++;}
  }
  if (maxval != NULL){
  *maxval = greatest;}

  ll_int *current = list;
  while (current != NULL) {
     ll_int *next = current->next;
     free(current);
     current = next;}

  return count;
}
