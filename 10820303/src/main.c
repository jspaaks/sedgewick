#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void print_data(const int ncols, const int (*ranges)[ncols], const int nrows, const int (*nsamples)[nrows], const double (*data)[nrows][ncols], const char *);

int main (void) {
    srand(time(NULL));
    fprintf(stdout, "Calculating mean and standard deviation for combinations of N and r.\n");
    int nrows = 4;
    int ncols = 3;
    int ranges[] = {10, 100, 1000};
    int nsamples[] = {1000, 10000, 100000, 1000000};
    double mus[nrows][ncols] = {};
    double sigmas[nrows][ncols] = {};

    for (int irow = 0; irow < nrows; irow++) {
        for (int icol = 0; icol < ncols; icol++) {
            double mu = 0;
            double sigma = 0;
            for (int isample = 0; isample < nsamples[irow]; isample++) {
                double u = ((double)rand()) / RAND_MAX;
                int r = 0;

                TODO

                mu += r / nsamples[irow];
                sigma += r * r / nsamples[irow];
            }
            mus[irow][icol] = mu;
            sigmas[irow][icol] = sqrt(sigma - mu * mu);
        }
    }
    print_data(ncols, &ranges, nrows, &nsamples, &mus, "means:");
    print_data(ncols, &ranges, nrows, &nsamples, &sigmas, "standard deviations:");
}

void print_data(const int ncols, const int (*ranges)[ncols], const int nrows, const int (*nsamples)[nrows], const double (*data)[nrows][ncols], const char * title) {
    fprintf(stdout, "\n%s\n", title);
    fprintf(stdout, "        r");
    for (int icol = 0; icol < ncols; icol++ ) {
        fprintf(stdout, " %7d   ", (*ranges)[icol]);
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "      N\n");
    for (int irow = 0; irow < nrows; irow++) {
        fprintf(stdout, "%7d  ", (*nsamples)[irow]);
        for (int icol = 0; icol < ncols; icol++ ) {
            fprintf(stdout, " % 10.2f", (*data)[irow][icol]);
        }
        fprintf(stdout, "\n");
    }
}
