#include <stdio.h>
#include <stdlib.h>

FILE *file;

int main(int argc, char **argv)
{
    unsigned long  size;

    if(argc!=3)
    {
        printf("Error ... syntax: Fillerfile  size  Fname \n\n");
        exit(1);
    }

    size = atoi(&*argv[1]);

    printf("Creating %d byte file '%s'...\n", size, &*argv[2]);

    if(!(file = fopen(&*argv[2], "w+")))
    {
        printf("Error opening file %s!\n\n", &*argv[2]);
        exit(1);
    }

    // fseek(file, size-1, SEEK_SET);
    // fprintf(file, "%c", 0x00);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c", rand());
    }

    fclose(file);
}