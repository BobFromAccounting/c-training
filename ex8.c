#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;

    if(argc == 2) {
        
        printf("You only have one arguement. You suck.\n");
    
    } else if (argc > 1 && argc < 5) {

        printf("Here's your arguments:\n");

        for (i = 1; i < argc; i++) {
            if (argv[(i + 1)] != NULL) {
                printf("[ %s ], ", argv[i]);
            } else {
                printf("and [ %s ].", argv[i]);
            }
        }

        printf("\n");

    } else {

        printf("You have too many arguments. You suck.\n");
    
    }

    return 0;
}