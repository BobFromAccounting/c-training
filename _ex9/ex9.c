#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    while (i < 25) {
        printf("%d\n", i);
        i++;
    }

    while (i != 0) {
        printf("%d\n", i);
        i--;
    }

    while (i < 100) {
        if (i != 0) {
            if (i % 15 == 0) {
                printf("fizzbuzz\n");
            } else if (i % 5 == 0) {
                printf("buzz\n");
            } else if (i % 3 == 0) {
                printf("fizz\n");
            } else {
                printf("%d\n", i);
            }            
        }

        i++;
    }

    return 0;
}