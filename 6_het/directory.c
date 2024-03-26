/*** Listing a directory ***/
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  DIR *d;
  struct dirent *entry;

  // Listing directory content manually
  d=opendir(".");
  printf(" -my own ls:\n");
  while((entry=readdir(d))!=NULL){
    int len = strlen((*entry).d_name);
    if((*entry).d_name[0]!='.' && strmp((*entry).d_name + len -4, ".txt") == 0)
      printf("%s\t",(*entry).d_name);
    }
  closedir(d);

  // Listing directory content by command
  printf("\n\n -system ls:\n");
  chdir("..");
  system("ls");
  return 0;
  }