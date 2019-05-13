#include <stdio.h>

#include "expr_tree.h"

void make_asm(double a, double b, FILE *fout) {
    fprintf(fout, "global FINIT\n\nglobal f1\nglobal f2\nglobal f3\n\n");
    fprintf(fout, "global a\nglobal b\n\n");
    fprintf(fout, "section .rodata\n");

    fprintf(fout, "\ta dq %lf\n", a);
    fprintf(fout, "\tb dq %lf\n", b);
}

void compile(FILE *fin, FILE *fout, FILE *js) {
    double a, b;
    fscanf(fin, "%lf%lf\n", &a, &b);

    char buff[100];
    fgets(buff, 100, fin);
    fgets(buff, 100, fin);
    
    // fprintf(js, "expr1 = %s", buff);

    fgets(buff, 100, fin);
    Node *tree = parse_string(buff);
    fprintf(js, "expr2 = '");
    print_tree(js, tree, 0);
    fprintf(js, "'");

    // fprintf(js, "expr3 = %s", buff);
}

int main(int argv, char** argc) {
    FILE *fin = fopen(argc[1], "r"), *fout = fopen(argc[2], "w");
    FILE *js = fopen("html/expr.js", "w");

    compile(fin, fout, js);

    fclose(fin);
    fclose(fout);
    fclose(js);

    return 0;
}