#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct node {
    int item;
    Node * next;
};

int eliminate (Node * first, int nelim);
Node * initialize (int nmembers);
void show_usage (void);

int eliminate (Node * node, const int nelim) {
    while (node != node->next) {
        for (int ielim = 0; ielim < nelim - 2; ielim++) {
            node = node->next;
        }
        Node * tmp = node->next->next;
        free(node->next);
        node->next = tmp;
        node = tmp;
    }
    return node->item;
}

Node * initialize (const int nmembers) {
    Node * first = malloc(1 * sizeof(Node));
    if (first == nullptr) {
        fprintf(stderr, "ERROR: Problem allocating memory for first Node, aborting.\n");
        exit(EXIT_FAILURE);
    }
    first->item = 1;
    Node * prev = first;
    for (int imember = 1; imember < nmembers; imember++) {
        Node * curr = malloc(1 * sizeof(Node));
        if (curr == nullptr) {
            fprintf(stderr, "ERROR: Problem allocating memory for Node, aborting.\n");
            exit(EXIT_FAILURE);
        }
        prev->next = curr;
        curr->item = imember + 1;
        prev = curr;
    }
    prev->next = first;
    return first;
}

int main (int argc, char * argv[]) {
    if (argc == 2 && strncmp("-h", argv[1], 3)) {
        show_usage();
        exit(EXIT_SUCCESS);
    }
    if (argc != 3) {
        show_usage();
        exit(EXIT_FAILURE);
    }
    int nmembers = atoi(argv[1]);
    int nelim = atoi(argv[2]);
    Node * first = initialize(nmembers);
    int item = eliminate(first, nelim);
    fprintf(stdout, "%d\n", item);
    exit(EXIT_SUCCESS);
}

void show_usage (void) {
    fprintf(stderr, "Usage: 109400001 NMEMBERS NELIM\n"
                    "    In a Josephus circle of NMEMBERS members, eliminate every NELIM-th\n"
                    "    member until there is just one left, then print its ID.\n");
}
