#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

    char * time_max[12];
    char * time_min[12];

    struct node * next;
    struct node * previous;

} node_t;

void print_list_of_times_max_over_min(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%s\n", current->time_max);
        printf("%s\n", current->time_min);

        current = current->next;
    }
}

void push_time_max_to_end_of_list(node_t * head, char * time_max) {
    node_t * current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->time_max = time_max;
    current->next->next = NULL;
}

void push_time_min_to_end_of_list(node_t * head, char * time_min) {
    node_t * current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->time_min = time_min;
    current->next->next = NULL;
}

void push_time_max_to_beginning_of_list(node_t ** head, char * time_max) {
    node_t * new_time_node_to_add;
    new_time_node_to_add = malloc(sizeof(node_t));

    new_time_node_to_add->time_max = time_max;
    new_time_node_to_add->next = *head;
    *head = new_time_node_to_add;
}

void push_time_min_to_beginning_of_list(node_t ** head, char * time_min) {
    node_t * new_time_node_to_add;
    new_time_node_to_add = malloc(sizeof(node_t));

    new_time_node_to_add->time_min = time_min;
    new_time_node_to_add->next = *head;
    *head = new_time_node_to_add;
}

int pop_time_max_from_beginning_of_list(node_t ** head) {
    int return_value = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    return_value = (*head)->time_max;
    free(*head);
    *head = next_node;

    return return_value;
}

int pop_time_min_from_beginning_of_list(node_t ** head) {
    int return_value = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    return_value = (*head)->time_min;
    free(*head);
    *head = next_node;

    return return_value;
}

int remove_time_max_from_end_of_list(node_t * head) {
    int return_value = 0;
    if (head->next == NULL) {
        return_value = head->time_max;
        free(head);
        head = NULL;
        return return_value;
    }

    node_t * current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }
}

int remove_time_min_from_end_of_list(node_t * head) {
    int return_value = 0;
    if (head->next == NULL) {
        return_value = head->time_min;
        free(head);
        head = NULL;
        return return_value;
    }

    node_t * current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }
}


int main()
{

    print_list(head);

    return 0;
}
    // FILE* stream = fopen("test.csv", "r");

    // char line[50];
    // while (fgets(line, 50, stream) != NULL)
    // {

    //     char* getTimeA = strtok(line, ",");
    //     strcpy(times->timeA, getTimeA);
    //     char* getTimeB = strtok(NULL, ", ");
    //     strcpy(times->timeB, getTimeB);
    //     printf("Field 2 would be %s\n", times->timeB);
    //     printf("Field 1 would be %s\n", times->timeA);
        
    //     times->next = head;
    //     head = times;


    //     // char* tempLine = strdup(line);
    //     // NOTE strtok clobbers tmp
    //     // free(tempLine);
    // }