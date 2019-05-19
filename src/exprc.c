#include <stdlib.h>
#include <stdio.h>

#include "expr_tree.h"
#include "make_asm.h"
#include "make_js.h"

void compile(FILE *fin, FILE *f_asm, FILE *f_js) {
    double a, b;
    fscanf(fin, "%lf%lf\n", &a, &b);

    char buff[100];

    fgets(buff, 100, fin);
    Node *tree1 = parse_string(buff);
    fgets(buff, 100, fin);
    Node *tree2 = parse_string(buff);
    fgets(buff, 100, fin);
    Node *tree3 = parse_string(buff);

    make_js(a, b, tree1, tree2, tree3, f_js);
    make_asm(a, b, tree1, tree2, tree3, f_asm);

    free_tree(tree1);
    free_tree(tree2);
    free_tree(tree3);
}

int main(int argv, char** argc) {
    FILE *fin = fopen(argc[1], "r"), *fout = fopen(argc[2], "w"), *js = fopen(argc[3], "w");

    compile(fin, fout, js);

    fclose(fin);
    fclose(fout);
    fclose(js);

    return 0;
}