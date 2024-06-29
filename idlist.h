#ifndef IDLIST_H
#define IDLIST_H

typedef struct IdNode {
    char* id;
    struct IdNode* next;
} IdNode;

typedef struct {
    IdNode* head;
} IdList;

IdList* create_id_list();
void add_id(IdList* list, char* id);
void free_id_list(IdList* list);

#endif
