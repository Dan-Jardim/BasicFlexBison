#ifndef PRINTLIST_H
#define PRINTLIST_H

typedef struct PrintNode {
    // Definição de PrintNode vai aqui
    struct PrintNode* next;
} PrintNode;

typedef struct {
    PrintNode* head;
} PrintList;

PrintList* create_print_list();
void add_print(PrintList* list, PrintNode* print);
void free_print_list(PrintList* list);

#endif
