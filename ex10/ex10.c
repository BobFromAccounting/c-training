#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    if (argc == 1) {
        printf("ERROR: You must enter one or more arguments.\n");
        return 1;
    }

    
    int i = 0;
    int j = 0;

    for (i = 1; i != argc; i++) {

        for (j = 0; argv[i][j] != '\0'; j++) {
            char letter = tolower(argv[i][j]);

            switch (letter) {
                case 'a':
                    printf("%d: 'A'\n", j);
                    break;

                case 'e':
                    printf("%d: 'E'\n", j);
                    break;

                case 'i':
                    printf("%d: 'I'\n", j);
                    break;

                case 'o':
                    printf("%d: 'O'\n", j);
                    break;

                case 'u':
                    printf("%d: 'U'\n", j);
                    break;

                case 'y':
                    if (j > 2) {
                        // it's only sometimes y
                        printf("%d: 'Y'\n", j);
                    }

                    break;

                default:
                    printf("%d: %c is not a vowel\n", j, letter);

            }
        }
    }

    return 0;
}