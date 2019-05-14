#ifndef _MAKE_ASM_H_
#define _MAKE_ASM_H_

#include "expr_tree.h"

void make_asm(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout);
int fill_label_arr(int i, double *label_arr, Node *tree);
void print_asm_func(const char *name, Node *tree, FILE *fout);
void print_asm_node(Node *tree, FILE *fout);

#endif // _MAKE_ASM_H_