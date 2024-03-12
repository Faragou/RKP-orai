/*** Using temporary file ***/
#include <stdio.h>

int main(){
  char tmpname[L_tmpnam];
  char text[100];
  char *filename;
  FILE *tmpfp;

  // Not existing filename can be used as temporary file
  filename = tmpnam(tmpname);
  printf("There is no file called \"%s\".\n", tmpname);
//  printf("There is no file called \"%s\".\n", filename);

  // Manipulation of temporary file
  tmpfp = tmpfile();
  if(tmpfp){
    fprintf(tmpfp,"It_is_not_importanat.\n");
    fseek(tmpfp,0L,SEEK_SET);
    fscanf(tmpfp,"%s",text);
    printf("Tempfile contains: %s\n",text);
    fclose(tmpfp);
    }
  else
    fprintf(stderr,"Temporary file problem!\n");

  return 0;
  }