/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include "hw2.h"

int next_collatz_number(int n) {
  if(n%2==0){
	  return n/2;}
  else{
	  return (n*3)+1;}
}

int count_collatz_steps(int n) {
  if (n==1){
	 return 0;}
  else{
	return (count_collatz_steps(next_collatz_number(n))+1);}
}

int maximum(int *nums, int len) {
  int max_val = *nums;
  for(int i = 0; i < len; i++){
  	if(*(nums + i) > max_val){
		max_val = *(nums + i);}
  }
  return max_val;
}

int sum_positive(int *nums, int len) {
  int sum = 0;
  for(int i = 0; i < len; i++){
  	if(*nums > 0){
		sum = sum + *nums;}	
	nums++;} 
  return sum;
}

int count_negative(int *nums, int len) {
  int total = 0;
  for(int i = 0; i < len; i++){
  	if(*nums < 0){
	total = total + 1;}
	nums++;}
  return total;
}
