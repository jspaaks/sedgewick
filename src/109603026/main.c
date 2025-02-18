#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

int main (int argc, char * argv[]) {
    if (argc != 4) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }
    if (strncmp("-h", argv[1], 3) == 0) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    int nmembers1 = atoi(argv[1]);
    int nmembers2 = atoi(argv[2]);
    int insert_at = atoi(argv[3]);

    if (nmembers1 < 1) {
        fprintf(stderr, "ERROR: Need at least 1 element to initialize the fi"
                "rst circular linked list, aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (nmembers2 < 1) {
        fprintf(stderr, "ERROR: Need at least 1 element to initialize the sec"
                "ond circular linked list, aborting.\n");
        exit(EXIT_FAILURE);
    }
    if (insert_at < 0 || insert_at > nmembers1) {
        fprintf(stderr, "ERROR: Value of INSERT_AT out of range, aborting.\n");
        exit(EXIT_FAILURE);
    }

    Node * list1 = initialize(nmembers1, 1);
    fprintf(stdout, "First linked list has %d member%s:\n", nmembers1, nmembers1 == 1 ? "" : "s");
    print(list1);

    Node * list2 = initialize(nmembers2, 101);
    fprintf(stdout, "Second linked list has %d member%s:\n", nmembers2, nmembers2 == 1 ? "" : "s");
    print(list2);

    // identify the node after which to insert a break
    Node * from1 = list1;
    int n1 = ((insert_at - 1) % nmembers1 + nmembers1) % nmembers1;
    for (int i = 0; i < n1; i++) {
        from1 = from1->next;
    }
    Node * to1 = from1->next;

    // identify the last node
    Node * from2 = list2;
    int n2 = nmembers2 - 1;
    for (int i = 0; i < n2; i++) {
        from2 = from2->next;
    }
    Node * to2 = from2->next;

    from1->next = to2;
    from2->next = to1;

    fprintf(stdout, "After inserting the second list into the first list at position %d:\n",
            insert_at);

    if (insert_at == 0) {
        print(list2);
    } else {
        print(list1);
    }

    destroy(&list1);

    exit(EXIT_SUCCESS);
}

void show_usage (FILE * stream) {
    fprintf(stream, "109603026 NMEMBERS1 NMEMBERS2 INSERT_AT\n"
                    "    Create a circular linked list of NMEMBERS1 members; create another\n"
                    "    linked list of NMEMBERS2 members; insert the second circular linked list\n"
                    "    into the first at index INSERT_AT; print the result.\n");
}
