#ifndef IDLIST_H
#define IDLIST_H

typedef struct IdNode {
    char* id;
    struct IdNode* next;
} IdNode;

typedef struct {
    IdNode* head;
} IdList;

IdNode* create_id_node(char* id);
IdNode* append_id_node(IdNode* list, IdNode* new_node);
void free_id_list(IdNode* list);
void print_id_node(IdNode* id_node, int depth);

#endif
