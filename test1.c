#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

    char * time_max;
    char * time_min;

    struct node * next;
    struct node * previous;

} node_t;

int populate_list(node_t * head, char * get_time_max, char * get_time_min) {
    node_t * current = head;
    node_t * prev;

    while (current != NULL) {

        strcpy(current->time_max, get_time_max);
        strcpy(current->time_min, get_time_min);

        prev = current;
        current = current->next;
    }

    return 0;

}

void print_list_of_times_max_over_min(node_t * head, char * get_time_max, char * get_time_min) {
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

char * pop_time_max_from_beginning_of_list(node_t ** head) {
    char * return_value;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return "Cannot Remove Item";
    }

    next_node = (*head)->next;
    return_value = (*head)->time_max;
    free(*head);
    *head = next_node;

    return return_value;
}

char * pop_time_min_from_beginning_of_list(node_t ** head) {
    char * return_value;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return "Cannot Remove Item";;
    }

    next_node = (*head)->next;
    return_value = (*head)->time_min;
    free(*head);
    *head = next_node;

    return return_value;
}

// char * remove_time_max_from_end_of_list(node_t * head) {
//     char * return_value;
//     if (head->next == NULL) {
//         return_value = head->time_max;
//         free(head);
//         head = NULL;
//         return return_value;
//     }

//     node_t * current = head;

//     while (current->next->next != NULL) {
//         current = current->next;
//     }
// }

// char * remove_time_min_from_end_of_list(node_t * head) {
//     char * return_value;
//     if (head->next == NULL) {
//         return_value = head->time_min;
//         free(head);
//         head = NULL;
//         return return_value;
//     }

//     node_t * current = head;

//     while (current->next->next != NULL) {
//         current = current->next;
//     }

// }


int main()
{

    FILE * stream = fopen("test.csv", "r");

    char * line = NULL;

    struct node_t * head;

    * head = malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    while (fgets(line, 32, stream) != NULL)
    {
        char * get_time_max;
        char * get_time_min;
        char temp_time_a = strtok(line, ",");
        char temp_time_b = strtok(NULL, ", ");
        double seconds = time_difference(temp_time_a, temp_time_b);

        print_list_of_times_max_over_min(head, get_time_max, get_time_min);

        
        // char* tempLine = strdup(line);
        // NOTE strtok clobbers tmp
        // free(tempLine);
    }

    return 0;
}