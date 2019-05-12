#include <stdio.h>

#include "expr_tree.h"

int main(int argv, char** argc) {
    FILE *fin = fopen(argc[1], "r"), *fout = fopen(argc[2], "w");

    double a, b;
    fscanf(fin, "%lf%lf", &a, &b);
    printf("%lf %lf\n", a, b);

    fclose(fin);
    fclose(fout);

    return 0;
}