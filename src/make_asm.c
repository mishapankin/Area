#include "make_asm.h"

#include <stdio.h>
#include <stdlib.h>

#include "expr_tree.h"

void make_asm(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout) {
    fprintf(fout, "global FINIT\n\nglobal f1\nglobal f2\nglobal f3\n\n");
    fprintf(fout, "global a\nglobal b\n\n");
    fprintf(fout, "section .rodata\n");

    fprintf(fout, "\ta dq %lf\n", a);
    fprintf(fout, "\tb dq %lf\n", b);
}