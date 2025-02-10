#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct node {
    int payload;
    Node * next;
};

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
    Node * first = node;
    size_t nnodes = 0;
    while (node->next != first) {
        node = node->next;
        nnodes++;
    }
    return nnodes + 1;
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
    Node * first = initialize(nmembers);
    size_t nnodes = len(first);
    fprintf(stdout, "Linked list has %zu member%s.\n", nnodes, nnodes == 1 ? "" : "s");
    exit(EXIT_SUCCESS);
}

void show_usage (void) {
    fprintf(stderr, "Usage: 109503024 NMEMBERS\n"
                    "    Create a circular linked list of NMEMBERS members, then determine and \n"
                    "    print its length.\n");
}
