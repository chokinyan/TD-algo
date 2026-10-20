#include "list.h"
#include <stdlib.h>

single_list new_list(long long first_val) {
    single_list l = {.data = first_val, .next = NULL};

    return l;
}

void insert(single_list* l, long long value, unsigned long index) {
    single_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++)
        current_node = current_node->next;

    if (current_node == NULL)
        return;

    single_list* new_node = malloc(sizeof(single_list));

    if (new_node == NULL)
        return;

    new_node->next = current_node->next;
    new_node->data = value;
    current_node->next = new_node;
}

void supress(single_list* l, unsigned long index) {
    single_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++)
        current_node = current_node->next;

    if (current_node == NULL || current_node->next == NULL)
        return;

    single_list* temp = current_node->next;

    current_node->next = temp->next;

    free(temp);
}

long long get(single_list* l, unsigned long index) {
    single_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++)
        current_node = current_node->next;

    if (current_node == NULL)
        return 0;

    return current_node->data;
}
