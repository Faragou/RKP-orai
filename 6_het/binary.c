#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int f = open("chart.bmp", O_WRONLY);

    if(f < 0){
        write(2, "error\n", 6);
        return 1;
    }

    char over[1000];

    for(int i = 0; i < 1000; i++){
        over[i] = 0x55;
    
    }

    lseek(f, -1000, SEEK_END);

    write(f, over, 1000);


    close(f);

    return 0;
}