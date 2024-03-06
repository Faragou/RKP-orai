/*** Bitwise operations with integers ***/
#include<stdio.h>

void int2bit(int Num){
  int Digit;
  unsigned int Mask=(1<<((8*sizeof(Num))-1));
  while(Mask!=0){
    Digit=((Num&Mask)==0)?0:1;
    printf("%d",Digit);
    Mask=Mask>>1;
    }
  }

int bitwise_inc(int N){
  int M=1;
  while(N&M){
    N&=~M;
    M<<=1;
    }
  return M|N;
  }

int bitwise_add(int A, int B){
  int M=1, r=0, ci=0;
  while(M){
    r|=(((A&M)^(B&M))^ci);
    ci=(((A&M)&(B&M))|(((A&M)^(B&M))&ci))<<1;
    M=M<<1;
    }
  return r;
  }

int bitwise_signchange(int x){
  return bitwise_inc(~x);
  }

int bitwise_sub(int A, int B){
  return bitwise_add(A,bitwise_signchange(B));
  }

int main(){
  int x, y;
  printf(" Enter two integers between %d and %d:\n",0x80000000,0x7fffffff);
  scanf("%d %d",&x,&y);
  printf("\n  ");
  int2bit(x);
  printf(" (%d)\n -",x);
  int2bit(y);
  printf(" (%d)\n  --------------------------------\n  ",y);
  int2bit(bitwise_sub(x,y));
  printf(" (%d)\n\n  ",x-y);
  printf("%d - %d = %d\n",x,y,bitwise_sub(x,y));
  return 0;
  }
