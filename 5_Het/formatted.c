#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(2000);

    FILE *out = fopen("out.txt", "w");

    if(out == NULL){
        fprintf(stderr, "file error");
        return 1;
    }

    for(int i = 0; i < 1000; i++){
        int r = rand() % (9999-1000+1)+1000;

        fprintf(out, "%d\n", r);
    }

    fclose(out);


    FILE *in = fopen("out.txt", "r");
    if(in == NULL){
        fprintf(stderr, "file error");
        return 1;
    }

    int row = 4;

    int pos = (row - 1) *5;

    fseek(in, pos, SEEK_SET);
    int res;

    fscanf(in, "%d", &res);

    printf("%d\n", res);


    fclose(in);
    return 0;
}