#include <stdio.h>
#include <stdlib.h>


#define MIN 1000
#define MAX 9999
#define COUNT 1000
#define TARGET 872

int main(){

    srand(2000);
    FILE *f = fopen("numbers.txt", "w");
    if(f == NULL){
        fprintf(stderr, "File opening problem!\n");
        return 1;
    }

    for(int i = 0; i <COUNT; i++){
        int num = (rand() % (MAX-MIN + 1)) + MIN;
        fprintf(f, "%d\n", num);
    }

    fclose(f);

    FILE *f2 = fopen("numbers.txt", "r");
    if(f2 == NULL){
        fprintf(stderr, "File opening problem!\n");
        return 1;
    }

    fseek(f2, 0, SEEK_SET);

    fclose(f2);

    return 0;
}