#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15;
// const char* getTime(char* line, int num)
// {
//     const char* token;
//     for (token = strtok(line, ",");
//             token && *token;
//             token = strtok(NULL, "\n"))
//     {
//         if (!--num) {
            
//             return token;

//         }
//     }
//     return NULL;
// }

typedef struct *TIMES
{

    char* timeA[12];
    char* timeB[12];

    char min[12];
    char max[12];

    struct TIMES* next;
    struct TIMES* previous;

} tTime;

int main()
{
    FILE* stream = fopen("test.csv", "r");

    char line[50];
    while (fgets(line, 50, stream) != NULL)
    {
        struct TIMES* times = malloc(sizeof(struct TIMES));
        char* getTimeA = strtok(line, ",");
        strdup(times->timeA, getTimeA);
        char* getTimeB = strtok(NULL, ", ");
        strdup(times->timeB, getTimeB);
        printf("Field 2 would be %s\n", times->timeB);
        printf("Field 1 would be %s\n", times->timeA);
        
        times->next = head;
        head = times;


        // char* tempLine = strdup(line);
        // NOTE strtok clobbers tmp
        // free(tempLine);
    }
}