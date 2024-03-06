#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define VERSION "1.2.7"
// ELSŐ FELADAT
char *Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char *Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


//Második feladat
int Measurement(int **Values)
{
    // Jelenlegi idő kiszámolása
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int seconds = tm_struct->tm_hour * 3600 + tm_struct->tm_min * 60 + tm_struct->tm_sec;

    // Mennyi értéket generálunk
    int max_values = (seconds % 900) + 1; // 900 seconds = 15 minutes
    *Values = (int *)malloc(max_values * sizeof(int));
    
    // Ha a negyedórától számolt másodperc kevesebb mint 100, akkor 100 értéket generálunk
    if (max_values < 100){
        max_values = 100;
    }
    
    srand(time(NULL));

    // Generate random values
    int current_value = 0;
    (*Values)[0] = current_value;
    
    for (int i = 1; i < max_values; i++)
    {

            int r = rand() % 31 + 1; // Random number between 1 and 31
        if (r <= 11)
        {
            current_value--;
        }
        else if (r >= 21)
        {
            current_value++;

        }
        (*Values)[i] = current_value;
    }

    return max_values;
}


//harmadik feladat
void BMPcreator(int *Values, int NumValues);

// ELSŐ FELADAT
void print_version_info()
{
    time_t T1;
    int T2;
    T2 = time(&T1);
    printf("Verzió: %s\n", VERSION);
    printf("Dátum: %s\n", ctime(&T1));
}

// ELSŐ FELADAT
void print_help()
{
    printf("Használat (Kapcsolók): ./chart [-send | -receive] [-file | -socket]\n");
    printf("Információs kapcsolók:\n");
    printf("  --version\tVerzió információ\n");
    printf("  --help\tSegítséghez használd a help kapcsolót\n");
}
// HARMADIK FELADAT
// Step 2: BMPcreator function definition
void BMPcreator(int* Values, int NumValues)
{
    unsigned long int fsize = (62 + (NumValues * NumValues));
    unsigned int padding = 0;
    int file = open("chart.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH);
    unsigned char** tomb = (unsigned char**)calloc(NumValues, sizeof(unsigned char*));
    

    unsigned char f_header[] = { 0x42, 0x4d,                 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,                                 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x0f,
    0x00, 0x00, 0x61, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xff, 0x00, 0xff, 0x00, 0x00, 0xff, 0xff,           };

    for (int i = 0; i < NumValues; ++i) {
        tomb[i] = (unsigned char*)calloc(NumValues, sizeof(unsigned char));
    }
    for(int i = 0; i < NumValues; ++i){
        int elem = (NumValues/2) + Values[i];
        if (elem > NumValues){
            elem = NumValues-1;
        }
        else if (elem < -(NumValues/2)){
            elem = 0;
        }
        tomb[elem][i] = 0x01;
    }

    write(file, f_header, sizeof(unsigned char) * 2);     
    write(file, &fsize, sizeof(int));      
    write(file, &f_header[2], sizeof(unsigned char) * 12); 
    write(file, &NumValues, sizeof(int));  
    write(file, &NumValues, sizeof(int));  
    write(file, &f_header[14], sizeof(unsigned char) * 36);    

    for (int i = 0; i < NumValues; i++){
        int x = 7;
        for (int j = 0; j < NumValues; ++j){           
            if (tomb[i][j] == 0x01){
                int ps = 1 << x;
                padding = padding + ps;
            }
            if (x == 24){                
                write(file, &padding, sizeof(int));
                padding = 0;                
                x = 7;
                continue;
            }
            if (x % 8 == 0){
                x = (j % 32) + 9;
            }
            --x;
        }    
        write(file, &padding, sizeof(int));       
        padding = 0;
    }
    free(tomb);
}

int main(int argc, char *argv[])
{
    //ELSŐ FELADAT
    if (strcmp(argv[0], "./chart") != 0)
    {
        printf("Hiba: Futtatandó fájl neve 'chart' legyen!\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "--version") == 0)
    {
        print_version_info();
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        print_help();
        return EXIT_SUCCESS;
    }

    // Alap módok
    char *mode = "-send";
    char *communication = "-file";

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-send") == 0 || strcmp(argv[i], "-receive") == 0)
        {
            mode = argv[i];
        }
        else if (strcmp(argv[i], "-file") == 0 || strcmp(argv[i], "-socket") == 0)
        {
            communication = argv[i];
        }
        else
        {
            printf("Hiba: Hibás argumentum. Használd a '--help' kapcsolót több információért.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Kiválasztott üzemmód: %s\n", mode);
    printf("Kiválasztott kommunikációs mód: %s\n", communication);

    
    int cnt = 0; //EZT MAJD TÖRÖLD KI TE CSICSKA
    
    //Második feladat kiiratása
    if (strcmp(mode, "-send") == 0)
    {
        int *values;
        int num_values = Measurement(&values);

        printf("Generated values:\n");
        for (int i = 0; i < num_values; i++)
        {
            printf("%d ", values[i]);
            cnt++; //EZ CSAK A TESZT MIATT VAN BENNE
        }
        printf("\n");

        BMPcreator(values, num_values);
        
        free(values);
    }

    // EZ CSAK A TESZT MIATT VAN BENNE
    printf("Mért értékek száma: %d\n", cnt);
    // Step 2: Call Measurement function if in send mode
    

    return EXIT_SUCCESS;
}

