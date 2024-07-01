#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "idlist.h"

IdNode* append_id_node(IdNode* list, IdNode* new_node) {
    new_node->next = list;
    return new_node;
}

IdNode* create_id_node(char* id) {
    IdNode* node = (IdNode*) malloc(sizeof(IdNode));
    node->id = strdup(id);
    node->next = NULL;
    
    return node;
}


void free_id_list(IdNode* list) {
    IdNode* current = list;
    IdNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}


void print_id_node(IdNode* id_node, int depth) {
    if (id_node == NULL) {
        printf("Id node is NULL\n");
        return;
    }
    print_indent(depth);
    printf("Identifier: %s\n", id_node->id);
}