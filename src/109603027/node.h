#ifndef NODE_H
#define NODE_H
#include <stddef.h>

typedef struct node Node;

struct node {
    int payload;
    Node * next;
};

void destroy (Node ** node);
Node * initialize (int nmembers, int start_at);
void print (Node * node);

#endif
