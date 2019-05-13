#include <stdio.h>

#include "expr_tree.h"

void compile(FILE *fin, FILE *fout) {
    fprintf(fout, "global FINIT\n\nglobal f1\nglobal f2\nglobal f3\n\n");
    fprintf(fout, "global a\nglobal b\n\n");
    fprintf(fout, "section .rodata\n");

    double a, b;
    fscanf(fin, "%lf%lf\n", &a, &b);
    fprintf(fout, "\ta dq %lf\n", a);
    fprintf(fout, "\tb dq %lf\n", b);
}

int main(int argv, char** argc) {
    // FILE *fin = fopen(argc[1], "r"), *fout = fopen(argc[2], "w");

    // compile(fin, fout);

    // fclose(fin);
    // fclose(fout);

    char buff[100];
    fgets(buff, 100, stdin);

    Node* nodes = parse_string(buff);
    print_tree(stdout, nodes, 0);

    return 0;
}