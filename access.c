#include "access.h"
#include <stdlib.h>
#include <stdio.h>

AccessTypeNode* create_access_node(AccessType type) {
    AccessTypeNode* new_node = (AccessTypeNode*)malloc(sizeof(AccessTypeNode));
    if (new_node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para um novo AccessTypeNode\n");
        exit(EXIT_FAILURE);
    }
    new_node->type = type;
    new_node->next = NULL;
    return new_node;
}


void free_access_list(AccessTypeNode* head) {
    AccessTypeNode* current = head;
    while (current != NULL) {
        AccessTypeNode* next = current->next;
        free(current);
        current = next;
    }
}