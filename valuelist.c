#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valuelist.h"

ValueList* create_value_list() {
    ValueList* list = (ValueList*) malloc(sizeof(ValueList));
    list->head = NULL;
    return list;
}

void add_value(ValueList* list, ValueNode* value) {
    value->next = list->head;
    list->head = value;
}

void free_value_list(ValueList* list) {
    ValueNode* current = list->head;
    ValueNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
