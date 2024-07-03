#include "stdio.h"

typedef struct {
    int p;
    int q;
} Edge;

static void init_labels (const int n, int (*)[n]);
static void printrow (const int, const Edge, const int n, const int (*)[n]);
static void qunion (const Edge, int n, int (*)[n]);

static void init_labels (const int n, int (*labels)[n]) {
    for (int i = 0; i < n; i++) {
        (*labels)[i] = i;
    }
}

int main (void) {
    Edge edges[12] = {
        { 3, 4 },
        { 4, 9 },
        { 8, 0 },
        { 2, 3 },
        { 5, 6 },
        { 2, 9 },
        { 5, 9 },
        { 7, 3 },
        { 4, 8 },
        { 5, 6 },
        { 0, 2 },
        { 6, 1 },
    };
    constexpr int nedges = sizeof(edges) / sizeof(edges[0]);
    constexpr int nlabels = 10;
    int labels[nlabels] = { 0 };
    init_labels(nlabels, &labels);
    fprintf(stdout, "---      quick union        ---\n");
    fprintf(stdout, "            0 1 2 3 4 5 6 7 8 9\n");
    fprintf(stdout, "i    edge   labels\n");
    for (int iedge = 0; iedge < nedges; iedge++) {
        Edge edge = edges[iedge];
        qunion(edge, nlabels, &labels);
        printrow(iedge, edge, nlabels, &labels);
    }
}

static void printrow (const int iedge, const Edge edge, const int n, const int (*labels)[n]) {
    fprintf(stdout, "%2d.   %d-%d  ", iedge, edge.p, edge.q);
    for (int i = 0; i < n; i++) {
        fprintf(stdout, " %d", (*labels)[i]);
    }
    fprintf(stdout, "\n");
}

static void qunion (const Edge edge, const int n, int (*labels)[n]) {
    int i = edge.p;
    int j = edge.q;
    while (i != (*labels)[i]) {
        i = (*labels)[i];
    }
    while (j != (*labels)[j]) {
        j = (*labels)[j];
    }
    if (i == j) return;
    (*labels)[i] = j;
}
