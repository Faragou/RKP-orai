/*** Bitwise operations with floats ***/
#include<stdio.h>

union var{
  int i;
  float f;
  };

void write_bin(float a){
  int i,d,size = 8*sizeof(a);
  union var aa;
  aa.f = a;
  unsigned int mask=(1<<(size-1));
  for(i=1;i<=size;i++){
    d = ((aa.i&mask)==0)?0:1;
    printf("%d",d);
    if(i%8==0) printf(" ");
    mask = mask>>1;
    }
  }

float power(float b, int e){
  float p = 1;
  if(e<0){
    e*=-1;
    b=1/b;
    }
  for(;e>0;e--)
    p*=b;
  return p;
  }

void write_dec(float a){
  int *aa;
  int i,d,size = 8*sizeof(a);
  int S,K = 0;
  double M = 0.0;
  unsigned int mask = (1<<(size-1));
  aa = (int*)&a;
  for(i=1;i<=size;i++){
    if(((*aa)&mask)==0) d = 0;
    else d = 1;
    if(i==1) S = d;
    if(i>=2 && i<=9){
      K += d*power(2,8-i+1);
      }
    if(i>=10){
      M += d*power(0.5,i-9);
      }
    mask = mask>>1;
    }
  K -= 127;
  printf("%.10f",power(-1,S)*power(2,K)*(1+M));
  }

int main(){
  float x = -2.4;
//  float x = -2.5;
  write_dec(x);
  printf(" = %.10f\n",x);
  write_bin(x);
  printf("\n");
  return 0;
  }
