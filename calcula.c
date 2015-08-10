#include <stdio.h>
#include "postfija.h"
#define TRUE = 1
#define FALSE = 0

int main( ){
  char expresion[201];
  gets( expresion );
  convert( expresion );
  return 0;
}