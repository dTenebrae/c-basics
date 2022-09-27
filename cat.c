#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;   // указатель на файл
    char *fname;  // имя файла

    for (int i = 1; i < argc; i++) {
        fname = argv[i];

        file = fopen(fname, "r");

        if (file == NULL) {
            printf("Could not open a file");
            return 1;
        }

        int chr = fgetc(file);
        while (chr != EOF) {
            putchar(chr);
            chr = fgetc(file);
        }
        fclose(file);

    }

    return 0;

}