#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1000

int main(){
    float asd [SIZE];

    for(int i = 0; i < SIZE; i++){
        if(i == 4){
        asd[i] = -314.159999;
        }
        else{
        asd[i] = -314.159302;
        }
    }

    int f = open("floats.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    int bytes = write(f, asd, SIZE * sizeof(float));

    close(f);

    float result;
    int in = open("floats.txt", O_RDONLY); 
    lseek(in, 4 * sizeof(float), SEEK_SET);

    int bt = read(in, &result, sizeof(float));

    printf("%d bytes read, value: %f\n", bt, result);

    close(bt);
    return 0;
}