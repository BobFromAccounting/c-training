#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char arg[], int argument_length);

void print_arguements(int argc, char *argv[])
{
    int i = 0;

    for (i = 1; i < argc; i++) {
        int argument_length = strlen(argv[i]);
        print_letters(argv[i], argument_length);
    }
}

void print_letters(char arg[], int argument_length)
{
    int i = 0;

    for (i = 0; i < argument_length; i++) {
        char ch = arg[i];

        if (isalpha(ch) || isblank(ch) || isdigit(ch)) {
            printf("'%c' === %d ",  ch, ch);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguements(argc, argv);
    return 0;
}