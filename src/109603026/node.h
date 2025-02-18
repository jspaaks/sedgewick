#ifndef NODE_H
#define NODE_H
#include <stddef.h>

typedef struct node Node;

struct node {
    int payload;
    Node * next;
};

size_t between (Node * from, const Node * to);
void destroy (Node ** node);
Node * initialize (int nmembers, int start_at);
size_t len (Node * node);
void print (Node * node);

#endif
