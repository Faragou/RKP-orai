/*** Example of multisource code using symbolic boolean values ***/
// gcc boolean.c BoolFunc.c

#include <stdio.h>
//#include "boolean.h"
#include "operator.h"

boolean IsPositive(float a);
boolean IsEven(int a);
boolean IsEqual(float a, float b);
void boolprint(char *form, boolean x);

int main(){
  boolean x,y,z;
  x = true;
  y = not IsEqual(3, 2.4);
  z = (x or y) and IsEven(321);
  boolprint(" x=%b.\n",x);
  boolprint(" The value of y is %b, as it is expected.\n",y);
  boolprint(" A %b value is stored in z.\n",z);
  return 0;
  }
