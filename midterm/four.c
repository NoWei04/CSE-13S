#include "midterm.h"

#include <stdio.h>

// PROBLEM 3
void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers) {
  // Your code here! Make them sorted!
  size_t i = 0;
  size_t j = 0;
  
  for(i = 0; i  < n_customers; i++){
     for(j = 0; j < n_customers - i; j++){
        if(customers[j].num_purchases < customers[j+1].num_purchases){
	ShoeCustomer k = customers[j];
	customers[j] = customers[j+1];
	customers[j+1] = k;}
     }   
  } 
}
