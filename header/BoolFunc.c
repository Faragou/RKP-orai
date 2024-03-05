/*** Boolean functions [without main()] ***/
#include "boolean.h"

#ifndef strcpy
  #include <string.h>
#endif

#ifndef printf
  #include <stdio.h>
#endif

boolean IsPositive(float a){
  return (a>0);
  }

boolean IsEven(int a){
  return 1-(a%2);
  }

boolean IsEqual(float a, float b){
  return (a==b);
  }

void boolprint(char *form, boolean x){
  // Not perfect!!! Not professional!!! Just example.
  char *pb;
  char tmp[1000];

  strcpy(tmp,form);
  pb=strstr(tmp,"%b");
  *pb='\0';
  printf("%s",tmp);
  if(x==true)
    printf("true");
  else
    printf("false");
  printf("%s",(pb+2));
  }
