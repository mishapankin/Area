#include "make_js.h"

#include <stdlib.h>
#include <stdio.h>

#include "expr_tree.h"

void make_js(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout) {
    fprintf(fout, "expr1 = 'f_1(x)=");
    print_tree(fout, tree1, 0);
    fprintf(fout, "'\n");

    fprintf(fout, "expr2 = 'f_2(x)=");
    print_tree(fout, tree2, 0);
    fprintf(fout, "'\n");

    fprintf(fout, "expr3 = 'f_3(x)=");
    print_tree(fout, tree3, 0);
    fprintf(fout, "'\n");
}