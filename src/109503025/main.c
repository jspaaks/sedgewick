#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct node {
    int payload;
    Node * next;
};

size_t between (Node * from, Node * to);
Node * initialize (int nmembers);
size_t len (Node * node);
void show_usage (void);

Node * initialize (const int nmembers) {
    Node * first = malloc(1 * sizeof(Node));
    if (first == nullptr) {
        fprintf(stderr, "ERROR: Problem allocating memory for first Node, aborting.\n");
        exit(EXIT_FAILURE);
    }
    first->payload = 1;
    Node * prev = first;
    for (int imember = 1; imember < nmembers; imember++) {
        Node * curr = malloc(1 * sizeof(Node));
        if (curr == nullptr) {
            fprintf(stderr, "ERROR: Problem allocating memory for Node, aborting.\n");
            exit(EXIT_FAILURE);
        }
        prev->next = curr;
        curr->payload = imember + 1;
        prev = curr;
    }
    prev->next = first;
    return first;
}

size_t len (Node * node) {
    return between(node, node) + 1;
}

size_t between (Node * from, Node * to) {
    Node * node = from;
    size_t nnodes = 0;
    while (node->next != to) {
        node = node->next;
        nnodes++;
    }
    return nnodes;
}

int main (int argc, char * argv[]) {
    if (argc != 2) {
        show_usage();
        exit(EXIT_FAILURE);
    }
    if (strncmp("-h", argv[1], 3) == 0) {
        show_usage();
        exit(EXIT_SUCCESS);
    }
    int nmembers = atoi(argv[1]);
    if (nmembers < 1) {
        fprintf(stderr, "ERROR: Need at least 1 element to initialize the circular linked list, aborting.\n");  
        exit(EXIT_FAILURE);
    }
    Node * first = initialize(nmembers);
    size_t nnodes = len(first);
    fprintf(stdout, "Linked list has %zu member%s.\n", nnodes, nnodes == 1 ? "" : "s");
    if (nmembers >= 5) {
        size_t b = between(first, first->next->next->next->next);
        fprintf(stdout, "The number of nodes between 1st and 5th node is %zu.\n", b);
    }
    exit(EXIT_SUCCESS);
}

void show_usage (void) {
    fprintf(stderr, "Usage: 109503025 NMEMBERS\n"
                    "    Create a circular linked list of NMEMBERS members, then determine and \n"
                    "    print its length. If length is at least 5, also print the number of\n"
                    "    nodes between the first node and the 5th node.\n");
}
