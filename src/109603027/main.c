#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);
Node * get_node_by_index (int idx, int nmembers, const Node * list);

Node * get_node_by_index (const int idx, const int nmembers, const Node * list) {
    Node * node = (Node *) list;
    int n = (idx % nmembers + nmembers) % nmembers;
    for (int i = 0; i < n; i++) {
        node = node->next;
    }
    return node;
}

int main (int argc, char * argv[]) {
    if (argc != 4) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }
    if (strncmp("-h", argv[1], 3) == 0) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    int nmembers = atoi(argv[1]);
    int move_from = atoi(argv[2]);
    int move_to = atoi(argv[3]);

    if (nmembers < 1) {
        fprintf(stderr,
                "ERROR: Need at least 1 element to initialize the cir"
                "cular linked list, aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (move_from < 0 || move_from >= nmembers) {
        fprintf(stderr, "ERROR: Value of MOVE_FROM out of range, aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (move_to < 0 || move_to >= nmembers) {
        fprintf(stderr, "ERROR: Value of MOVE_TO out of range, aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (move_from == move_to) {
        fprintf(stderr, "ERROR: Value of MOVE_FROM is same as MOVE_TO, aborting.\n");
        exit(EXIT_FAILURE);
    }

    Node * list = initialize(nmembers, 100);
    fprintf(stdout, "Linked list has %d member%s:\n", nmembers, nmembers == 1 ? "" : "s");
    print(list);

    // identify the node preceding the node that we want to move
    Node * preceding_from = get_node_by_index(move_from - 1, nmembers, list);
    Node * from = preceding_from->next;

    // identify the node preceding the node that we want to move
    Node * preceding_to = get_node_by_index(move_to - 1, nmembers, list);
    Node * to = preceding_to->next;

    if (from != preceding_to) {
        preceding_from->next = from->next;
        preceding_to->next = from;
        from->next = to;
    }

    fprintf(stdout, "After moving the node from %d to %d:\n", move_from, move_to);

    if (move_from == 0) {
        print(preceding_from->next);
    } else if (move_to == 0) {
        print(from);
    } else {
        print(list);
    }

    destroy(&list);

    exit(EXIT_SUCCESS);
}

void show_usage (FILE * stream) {
    fprintf(stream, "109603027 NMEMBERS MOVE_FROM MOVE_TO\n"
                    "    Create a circular linked list of NMEMBERS members; move the element\n"
                    "    at MOVE_FROM to MOVE_TO; print the before and after list.\n");
}
