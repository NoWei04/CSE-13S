#include "midterm.h"
   
long long *fibonacci_numbers(size_t n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 0, 1, 1, 2, 3, 5, 8, ...
  
  long long *numbers = malloc(n * sizeof(long long));	
  size_t i = 2;
  
  if(numbers == NULL){
     return NULL;}

  if(n >= 0){
      numbers[0] = 0;}

  if(n >= 1){
      numbers[1] = 1;} 
  
  while (i < n){
      numbers[i] = numbers[i-2] +  numbers[i-1]; 
      i++;}

   return numbers;
}

