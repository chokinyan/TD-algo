#include "list.h"
#include <stdlib.h>

circular_list new_list(long long first_val) {
    circular_list l = {.data = first_val, .next = NULL};

    return l;
}

void insert(circular_list* l, long long value, unsigned long index) {
    circular_list* current_node = l;

    for (unsigned long i = 0; i < index; i++)
        current_node = current_node->next ? current_node->next : l;

    circular_list* new_node = malloc(sizeof(circular_list));

    if (new_node == NULL)
        return;

    new_node->next = current_node->next ? current_node->next : l;
    new_node->data = value;
    current_node->next = new_node;
}

void supress(circular_list* l, unsigned long index) {
    circular_list* current_node = l;

    for (unsigned long i = 0; i < index; i++)
        current_node = current_node->next ? current_node->next : l;

    circular_list* temp = current_node->next;

    if (temp == NULL || temp == l)
        return;

    current_node->next =
        (temp->next == l && current_node == l) ? NULL : temp->next;

    free(temp);
}

long long get(circular_list* l, unsigned long index) {
    circular_list* current_node = l;

    for (unsigned long i = 0; i < index; i++)
        current_node = current_node->next ? current_node->next : l;

    return current_node->data;
}
