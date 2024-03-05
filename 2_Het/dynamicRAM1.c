/*** Reverse file by stack (linked list) ***/
#include<stdio.h>
#include<malloc.h>

// New type for letter
typedef struct LetterUnit{
  char letter;
  struct LetterUnit *next;
  } Letter;

// Saving a letter into the stack
void Push(Letter** h, char c){
  Letter* temp;
  temp = (Letter*)malloc(sizeof(Letter));
  if(temp!=NULL){
    (*temp).letter = c;
    (*temp).next = (*h);
    (*h) = temp;
    }
  else
    printf("\tThe memory is full!\n");
  }

// Deleting a letter from the stack
char Pop(Letter** h){
  char c;
  Letter* temp;
  temp=(*h);
  if((*h)!=NULL){
    c = (**h).letter;
    (*h) = (**h).next;
    free(temp);
    }
  else
    printf("\tThe stack is empty!\n");
  return c;
  }

int main(int argc, char *argv[]){
  char Character;
  FILE *File;
  Letter *Head;

  if(argc==1) {
    fprintf(stderr," Filename is necessary!\n");
    return 1;
    }

  File = fopen(argv[1],"r");
  if(File==NULL) {
    fprintf(stderr," Error during file open!\n");
    return 2;
    }
  Head = NULL;
  do{
    fscanf(File,"%c",&Character);
    if(feof(File)) break;
    Push(&Head,Character);
    }
  while(1);
  fclose(File);

  File = fopen(argv[1],"w");
  while(Head!=NULL){
    Character = Pop(&Head);
    fprintf(File,"%c",Character);
    }
  fclose(File);

  return 0;
  }