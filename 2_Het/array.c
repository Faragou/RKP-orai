/*** Print continuous memory as Matrix ***/
#include<stdio.h>
#include<malloc.h>

void MX_Print(int *MX, int N, int M){
  int i, j;

  for(i=0;i<N;i++){
    for(j=0;j<M;j++)
      printf("%3d",*(MX+i*M+j));
    printf("\n");
    }
  printf("\n");
  }

int main(){
  int A[8]    = {-8,-7,-6,-5,-4,-3,-2,-1};
  int B[2][3] = {{1,2,3},{4,5,6}};

  MX_Print(A,1,8);
  MX_Print(A,2,4);
  MX_Print((int*)B,3,2);
  MX_Print((int*)B,2,3);
  MX_Print(&A[2],2,2);
  return 0;
  }
