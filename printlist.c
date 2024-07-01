#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printlist.h"

PrintList* create_print_list() {
    PrintList* list = (PrintList*) malloc(sizeof(PrintList));
    list->head = NULL;
    return list;
}

void add_print(PrintList* list, PrintNode* print) {
    print->next = list->head;
    list->head = print;
}

void free_print_list(PrintList* list) {
    PrintNode* current = list->head;
    PrintNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
