#include <stdio.h>

int main(void) {
  // Finish this program. You'll almost certainly want to use a loop of some
  // kind, getchar() and putchar(). Remember that the output of getchar() is the
  // symbol EOF when you get to the end of the input.
  
	int c = 0;

	while(c = getchar()){
		putchar(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c== 'U'){
			putchar(c);}
		if c == EOF{
			break;
		}
  return 0;
}
