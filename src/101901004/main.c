#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Edge;

static void init_labels (const int n, int (*)[n]);
static void printrow (const int, const Edge, const int n, const int (*)[n], bool, int);
static bool qfind (const Edge, const int n, int (*)[n], int *);

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
    fprintf(stdout, "---       quick find        ---\n");
    fprintf(stdout, "            0 1 2 3 4 5 6\n");
    fprintf(stdout, "i    edge   labels        naccess\n");
    for (int iedge = 0; iedge < nedges; iedge++) {
        Edge edge = edges[iedge];
        bool changed = qfind(edge, nlabels, &labels, &naccess);
        printrow(iedge, edge, nlabels, &labels, changed, naccess);
    }
    return EXIT_SUCCESS;
}

static void printrow (const int iedge, const Edge edge, const int n, const int (*labels)[n],
                      bool changed, int naccess) {
    fprintf(stdout, "%2d.   %d-%d  ", iedge, edge.p, edge.q);
    for (int i = 0; i < n; i++) {
        if (changed) {
            fprintf(stdout, " %1d", (*labels)[i]);
        } else {
            fprintf(stdout, " .");
        }
    }
    fprintf(stdout, " %3d", naccess);
    fprintf(stdout, "\n");
}

static bool qfind (const Edge edge, const int n, int (*labels)[n], int * naccess) {
    int p = edge.p;
    int q = edge.q;
    if ((*labels)[p] == (*labels)[q]) {
        *naccess += 2;
        return false;
    }
    *naccess += 2;
    int t = (*labels)[p];
    *naccess += 1;
    for (int i = 0; i < n; i++) {
        if ((*labels)[i] == t) {
            (*labels)[i] = (*labels)[q];
            *naccess += 2;
        }
        *naccess += 1;
    }
    return true;
}
