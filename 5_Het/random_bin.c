#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1000

int main(){
    int asd [SIZE];

    for(int i = 0; i < SIZE; i++){
        int r = rand() % (9999-0+1)+0;
        asd[i] = r;
    }

    int f = open("ints.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    int bytes = write(f, asd, SIZE * sizeof(int));

    printf("%d\n ", asd[4]);

    close(f);

    int result;
    int in = open("ints.txt", O_RDONLY); 
    lseek(in, 4 * sizeof(int), SEEK_SET);

    int bt = read(in, &result, sizeof(int));

    printf("%d bytes read, value: %d\n", bt, result);

    close(bt);
    return 0;
}