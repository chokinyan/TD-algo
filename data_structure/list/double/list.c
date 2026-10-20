#include "list.h"
#include <stdlib.h>

double_list new_list(long long first_val) {
    double_list l = {.data = first_val, .next = NULL, .previous = NULL};

    return l;
}

void insert(double_list* l, long long value, unsigned long index) {

    double_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++) {
        current_node = current_node->next;
    }

    if (current_node == NULL)
        return;

    double_list* new_node = malloc(sizeof(*new_node));

    if (new_node == NULL)
        return;

    new_node->data = value;
    new_node->previous = current_node;
    new_node->next = current_node->next;

    if (current_node->next != NULL) {
        current_node->next->previous = new_node;
    }
    current_node->next = new_node;
}

void supress(double_list* l, unsigned long index) {
    double_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++) {
        current_node = current_node->next;
    }

    if (current_node == NULL || current_node->next == NULL)
        return;

    double_list* temp = current_node->next;

    current_node->next = temp->next;

    if (temp->next != NULL) {
        temp->next->previous = current_node;
    }

    free(temp);
}

long long get(double_list* l, unsigned long index) {
    double_list* current_node = l;

    for (unsigned long i = 0; i < index && current_node != NULL; i++) {
        current_node = current_node->next;
    }

    if (current_node == NULL)
        return 0;

    return current_node->data;
}
