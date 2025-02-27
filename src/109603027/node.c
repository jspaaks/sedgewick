#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t len (Node * node);

size_t between (Node * from, const Node * to) {
    Node * node = from;
    size_t nnodes = 0;
    while (node->next != to) {
        node = node->next;
        nnodes++;
    }
    return nnodes;
}

void destroy (Node ** node) {
    size_t nnodes = len(*node);
    Node * curr = *node;
    for (size_t inode = 0; inode < nnodes; inode++) {
        Node * tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *node = nullptr;
}

Node * initialize (const int nmembers, int start_at) {
    Node * first = malloc(1 * sizeof(Node));
    if (first == nullptr) {
        fprintf(stderr, "ERROR: Problem allocating memory for first Node, aborting.\n");
        exit(EXIT_FAILURE);
    }
    first->payload = start_at;
    Node * prev = first;
    for (int imember = 1; imember < nmembers; imember++) {
        Node * curr = malloc(1 * sizeof(Node));
        if (curr == nullptr) {
            fprintf(stderr, "ERROR: Problem allocating memory for Node, aborting.\n");
            exit(EXIT_FAILURE);
        }
        prev->next = curr;
        curr->payload = start_at + imember;
        prev = curr;
    }
    prev->next = first;
    return first;
}

size_t len (Node * node) {
    return between(node, node) + 1;
}

void print (Node * node) {
    Node * curr = node;
    do {
        fprintf(stdout, " %d", curr->payload);
        curr = curr->next;
    } while (curr != node);
    fprintf(stdout, "\n");
}
