/*** Example operations with pointers ***/
#include<stdio.h>
#define LENGTH 100

void upper(char* string, int *length, int *changed, char **fromA){
  *length = *changed = 0;
  (*fromA) = NULL;
  for(;(*string)!='\0';string++){
    if((*string)>='a' && (*string)<='z'){
      (*string) -= 32;
      (*changed)++;
      }
    if((*string)=='A')
      (*fromA) = string;
    (*length)++;
    }
  if((*fromA)==NULL)
    (*fromA) = string;
  }

int main(){
  int lower, chars;
  char word[LENGTH];
  char *StartA;

  printf(" Write a word!\n  The word: ");
  scanf("%s",word);
  upper(word,&chars,&lower,&StartA);
  printf("  Uppercase word: %s\n",word);
  printf("  Last substring starts with 'A': %s\n",StartA);
  printf("  Number of characters: %d\n",chars);
  printf("  Number of changed lowercase letters: %d\n",lower);
  printf("  Number of unused places in the array: %ld\n",sizeof(word)-chars-1); // -1 for '\0'
  return 0;
  }
