/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool str_suffix(char *haystack, char *needle) {
  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);
  
  if(needle_len > haystack_len){
	 return false;}
  
  char *hptr = haystack + (haystack_len - needle_len);
  char *nptr = needle;  
  
  while(*nptr != '\0'){
    if(*hptr != *nptr){
      return false;}
	hptr++;
	nptr++;}

 return true;
}

char *str_repeat(char *s, int n) {
  int len = strlen(s);
  
  char *out = malloc(sizeof(char) * (len * n + 1 ));
  out[0] = '\0';
    
  for(int i = 0; i < n; i++){
    strcat(out, s);}

  return out;
}

bool str_is_palindrome(char *s) {
  int len = strlen(s);
  int j = 0;
  char *original = malloc(len + 1);
  char *reversed  = malloc(len + 1);
  
  if(original == NULL|| reversed == NULL){
    return false;}

  for(int i = 0; i < len; i++){
    if(isalpha(s[i])){
    original[j++] = tolower(s[i]);}
 	} 
  
  original[j] = '\0';

  for(int i = 0; i < j; i++){
    reversed[i] = original[j - i - 1];}

  reversed[j] = '\0';

  if(strcmp(original,reversed) == 0){
    free(original);
    free(reversed);
    return true;}

  else{
    free(original);
    free(reversed);
    return false;}
 }

float dot_product(float *vec_a, float *vec_b, int length) {
  float final = 0;
  float *a = vec_a;
  float *b = vec_b;
   
  for(int i = 0; i < length; i++){
    final = final + (*a * *b);	  
    a++;
    b++;}  	  

  return final;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
  for(int i = 0; i < length; i++){
     initial = f(initial, nums[i]);}	  
  return initial;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!
int find_max(int a, int b){
   if(a > b){
	return a;}

   else {
	return b;}   
}

int maximum_with_reduce(int *nums, int length) {
  int max = nums[0];
  return reduce(nums, length, find_max, max);
}

int add_val(int sum, int num){	
   if(num >= 0){
      return num + sum;}
   return sum;
}

int sum_positive_with_reduce(int *nums, int length) {
  return reduce(nums, length, add_val, 0);}

