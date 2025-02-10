#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Edge;

static void init_labels (const int n, int (*)[n]);
static void printrow (const int, const Edge, const int n, const int (*)[n], int);
static void qunion (const Edge, int n, int (*)[n], int *);

static void init_labels (const int n, int (*labels)[n]) {
    for (int i = 0; i < n; i++) {
        (*labels)[i] = i;
    }
}

int main (void) {
    int naccess = 0;
    Edge edges[] = {
        { 0, 2 },
        { 1, 4 },
        { 2, 5 },
        { 3, 6 },
        { 0, 4 },
        { 6, 0 },
        { 1, 3 },
    };
    constexpr int nedges = sizeof(edges) / sizeof(edges[0]);
    constexpr int nlabels = 7;
    int labels[nlabels] = { 0 };
    init_labels(nlabels, &labels);
    fprintf(stdout, "---      quick union        ---\n");
    fprintf(stdout, "            0 1 2 3 4 5 6\n");
    fprintf(stdout, "i    edge   labels        naccess\n");
    for (int iedge = 0; iedge < nedges; iedge++) {
        Edge edge = edges[iedge];
        qunion(edge, nlabels, &labels, &naccess);
        printrow(iedge, edge, nlabels, &labels, naccess);
    }
    exit(EXIT_SUCCESS);
}

static void printrow (const int iedge, const Edge edge, const int n, const int (*labels)[n],
                      int naccess) {
    fprintf(stdout, "%2d.   %d-%d  ", iedge, edge.p, edge.q);
    for (int i = 0; i < n; i++) {
        fprintf(stdout, " %d", (*labels)[i]);
    }
    fprintf(stdout, " %3d", naccess);
    fprintf(stdout, "\n");
}

static void qunion (const Edge edge, const int n, int (*labels)[n], int * naccess) {
    int i = edge.p;
    int j = edge.q;
    while (i != (*labels)[i]) {
        i = (*labels)[i];
        *naccess += 2;
    }
    *naccess += 1;
    while (j != (*labels)[j]) {
        j = (*labels)[j];
        *naccess += 2;
    }
    *naccess += 1;
    if (i == j) return;
    (*labels)[i] = j;
    *naccess += 1;
}
