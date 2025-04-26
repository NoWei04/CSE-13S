#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  // your code here
	return M_PI * radius * radius;
}

double area_of_ring(double outer_radius, double inner_radius) {
  // your code here
	double area = (M_PI * outer_radius * outer_radius) - (M_PI * inner_radius * inner_radius);
  return area;
}

int bigger_minus_smaller(int a, int b) {
  // your code here
  	int result = 0;
	if(a >= b){
		result = a-b;}
	else{
		result = b-a;}
	return result;
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
	if((x >= lower_bound) && (x <=  upper_bound)){
		return true;}
	else{
	      	return false;}
}

int sum_of_greater_squares(int a, int b, int c) {
	int a2 = a*a;
	int b2 = b*b;
	int c2 = c*c;

	if (a2 >= b2 && a2 >= c2) {
		if(b2 >= c2){
			return a2 + b2;}
		else{
			return a2 + c2;}
	}
       	else if (b2 >= a2 && b2 >= c2){
		if(a2 >= c2){
			return b2 + a2;}
		else{
			return b2 + c2;}
	}
       	else {
	       	if(a2 >= b2){
			return c2 + a2;}
		else{
			return c2 + b2;}
	}
}
