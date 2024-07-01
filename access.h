#ifndef ACCESS_H
#define ACCESS_H

typedef enum {
    ACCESS_INPUT,
    ACCESS_OUTPUT
} AccessType;

typedef struct AccessTypeNode {
    AccessType type;
    struct AccessTypeNode* next;
} AccessTypeNode;


AccessTypeNode* create_access_node(AccessType type);
void free_access_list(AccessTypeNode *head);

#endif 