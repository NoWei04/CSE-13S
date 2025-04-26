#include "final.h"
#include <stdio.h>

size_t row_index_with_lowest_sum(int **matrix, size_t rows, size_t cols) {
  int lowest_index = 0;
  int lowest_sum = 0;

  for(size_t i = 0; i < rows; i++){
     int sum = 0;
     for(size_t j = 0; j < cols; j++){
        sum += matrix[i][j];}

     if(i == 0 || sum < lowest_sum){
        lowest_sum = sum;
        lowest_index = i;}
  }
  return lowest_index;
}
