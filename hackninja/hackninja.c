#include <stdio.h>
#include <stdlib.h>

void countUp(int start)
{
    int i = 0;
    for (i = 1; i < 11; i += 1) {
        if (i == 1) {
            printf("%d ", start + i);
        } else {
            if (i != 10) {
                printf("then %d ", start + i);
            } else {
                printf("then %d\n", start + i);
            }
        }
    }
}

int main(int argc, char *argv[])
{   
    if (argc < 2) {
        
        printf("USAGE: <starting number>\n");
        exit(1);        
    }

    int start = strtol(argv[1], NULL, 10);

    countUp(start);
}