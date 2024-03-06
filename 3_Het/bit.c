/*** Example of bit operations ***/
#include<stdio.h>

int main(){
  char c; // signed

  // bitwise AND
  c = 234&114; // 0xEA & 0x72  a biteken végez műveletet az & és a | operátor
  printf("%c",c);

  // bitwise OR
  c = 64|41; // 0x40 | 0x29
  printf("%c",c);

  // bitwise XOR
  c = 123^15; // 0x7B ^ 0x0F
  printf("%c",c);

  // bitwise NOT
  c = 136;
  c = ~c; // ~0x88
  printf("%c",c);

  // SHIFT LEFT
  c = 109;
  c = c<<3; // 0x6D << 3
  printf("%c",c+1);

  // ARITHMETIC SHIFT RIGHT
  c = 231;
  c = c>>1; // 0xE7 >> 1
  printf("%c",c-128);

  // LOGIC SHIFT RIGHT
  c = 202;
  c = (unsigned char)c>>1; // (unsigned char)0xCA >> 1
  printf("%c\n",c);

  return 0;
  }