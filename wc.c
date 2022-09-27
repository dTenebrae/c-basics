#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;   // указатель на файл
    char *fname;  // имя файла
    char *option; // ключ

    // TODO можно сделать значение по умолчанию, без указания ключа
    if (argc != 3) {
        printf("Wrong arguments\n");
        return 1;
    }

    option = argv[1];

    fname = argv[2];

    file = fopen(fname, "r");

    if (file == NULL) {
        printf("Could not open a file");
        return 1;
    }


    if ((strcmp(option, "-c") == 0) || (strcmp(option, "--bytes") == 0)) {
        int bytes = 0;
        int chr = fgetc(file);

        while (chr != EOF) {
            bytes++;
            chr = fgetc(file);
        }

        printf("%d\n", bytes);
        return 0;

    } else if ((strcmp(option, "-l") == 0) || (strcmp(option, "--lines") == 0)) {
        int lines = 0;
        int chr = fgetc(file);

        while (chr != EOF) {
            if (chr == '\n') { lines++; }
            chr = fgetc(file);
        }
        fclose(file);
        printf("%d\n", lines);
        return 0;

    } else if ((strcmp(option, "-w") == 0) || (strcmp(option, "--words") == 0)) {
        int words = 0;
        int chr = fgetc(file);

        while (chr != EOF) {
            if ((chr == '\t') || (chr == ' ') || (chr == '\n')) { words++; }
            chr = fgetc(file);
        }

        printf("%d\n", words);
        return 0;
    } else {
        printf("Unknown argument\n");
        return 1;
    }
}