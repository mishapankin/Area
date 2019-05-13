#include <stdlib.h>
#include <stdio.h>

#include "expr_tree.h"
#include "make_asm.h"
#include "make_js.h"

void compile(FILE *fin, FILE *fout, FILE *js) {
    double a, b;
    fscanf(fin, "%lf%lf\n", &a, &b);

    char buff[100];

    fgets(buff, 100, fin);
    Node *tree1 = parse_string(buff);
    fgets(buff, 100, fin);
    Node *tree2 = parse_string(buff);
    fgets(buff, 100, fin);
    Node *tree3 = parse_string(buff);

    make_js(a, b, tree1, tree2, tree3, js);

    // free(tree1);
    // free(tree2);
    // free(tree3);
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