#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;

  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }

  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }

  long result = 0;
  long number = 0;
  char operator = 0;
  int value = 1;

  while(fgets(buffer, BUFSIZE, infile)) {
    remove_newline(buffer, BUFSIZE);

    if(buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {
      operator = buffer[0];}

    else{
      number = strtol(buffer, NULL, 10);

      if(value){
        result = number;
        value = 0;}

      else{
        if(operator == '+'){
          result += number;}
        else if(operator == '-'){
          result -= number;}
        else if(operator == '*'){
          result *= number;}
        else if(operator == '/'){
          if(number == 0) {
            printf("ERROR\n");
            fclose(infile);
            return 1;}
          result /= number;}
      }
    }
  }

  printf("%ld\n", result);
  return 0;
}


