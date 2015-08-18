#include <stdio.h>
#include <math.h>
#include "postfija.h"
#define TRUE = 1
#define FALSE = 0

int main( ){
  int bytes_read;
  size_t nbytes = 100;
  char *expresion;

  bytes_read = getline (&expresion, &nbytes, stdin);

  convert( expresion );
  return 0;
}