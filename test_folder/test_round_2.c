#include "list.h"

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List * list)
{
    LIST_FOREACH(list, first, next, cur) {
        if (cur->prev) {
            free(cur->previous);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List * list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->time_max);
        free(cur->time_min);
    }
}

void List_clear_destroy(List * list)
{
    List_clear(list);
    List_destroy(list);
}

void List_push(List * list, void *time_max, void *time_min)
{
    Node *node = calloc(1, sizeof(Node));
    check_mem(node);

    node->time_max = time_max;
    node->time_min = time_min;

    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = list->last;
        list->last = node;
    }

    list->count++;
}

void *List_pop(List * list)
{
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List * list, void *value)

struct Node *Node_create(char *time_max, char *time_min, struct Node *previous, struct Node *next)
{
    struct Node *times = malloc(sizeof(struct Node));
    assert(*times != NULL);

    times->time_max = strdup(time_max);
    times->time_min = strdup(time_min);
    times->previous = previous;
    times->next     = next;

    return times;
}

void Node_destroy(struct Node *times)
{
    assert(times != NULL);

    free(times->time_max);
    free(times->time_min);
    free(times);
}

void print_lists()
{
    // todo: fill in this with printf instructions to view the linked lists
}

int main()
{
    FILE *stream = fopen("test.csv", "r");

    char *line;

    struct Node *head = malloc(sizeof(Node));

    assert(head != NULL)

    while (fgets(line, 32, stream) != NULL)
    {
        /* write functions to create lists and begin populating nodes to chain linked lists together doubly and then lastly print them with time max in order of read file, and time min in reverse order. */
    }

    return 0;
}