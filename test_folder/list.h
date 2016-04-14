#ifndef List_h
#define List_h

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


struct Node;

typedef struct Node {
    struct Node *next;
    struct Node *previous;

    void *time_max;
    void *time_min;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int count;
} List;

List *List_create();
void List_destroy(List * list);
void List_clear(List * list);
void List_clear_destroy(List * list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List * list, void *value);
void *List_pop(List * list);
void List_unshift(List * list, void *value);
void *List_shift(List * list, void *value);

void *list_remove(List * list, ListNode * node);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                                   ListNode *V = NULL;\
for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif