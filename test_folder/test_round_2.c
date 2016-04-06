#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Node {

    char *time_max;
    char *time_min;

    struct Node *next;
    struct Node *previous;

};

struct Node *Node_create(char *time_max, char *time_min, struct Node *previous, struct Node *next)
{
    struct Node *field = malloc(sizeof(struct Node));
    assert(*field != NULL);

    field->time_max = strdup(time_max);
    field->time_min = strdup(time_min);
    field->previous = previous;
    field->next     = next;

    return field;
}

void Node_destroy(struct Node *field)
{
    assert(field != NULL);

    free(field->time_max);
    free(field->time_min);
    free(field);
}

void print_lists()
{
    // todo: fill in this with printf instructions to view the linked lists
}

int main()
{
    FILE *stream = fopen("test.csv", "r");

    char *line;

    struct node_t *head;

    *head = malloc(sizeof(node_t));

    assert(head != NULL)

    while (fgets(line, 32, stream) != NULL)
    {
        /* write functions to create lists and begin populating nodes to chain linked lists together doubly and then lastly print them with time max in order of read file, and time min in reverse order. */
    }

    return 0;
}