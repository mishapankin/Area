#include "make_asm.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "expr_tree.h"

#define EULER 2.718281828
#define MAX_CONST_SIZE 100

void make_asm(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout) {
    fprintf(fout, "global INIT_FPU\n\nglobal f1\nglobal f2\nglobal f3\n\n");
    fprintf(fout, "global a\nglobal b\n\n");

    fprintf(fout, "section .rodata\n");
    fprintf(fout, "\ta dq %lf\n", a);
    fprintf(fout, "\tb dq %lf\n\n", b);

    double label_arr[MAX_CONST_SIZE];
    int label_i = 0;
    label_i = fill_label_arr(label_i, label_arr, tree1);
    label_i = fill_label_arr(label_i, label_arr, tree2);
    label_i = fill_label_arr(label_i, label_arr, tree3);

    for (int i = 0; i < label_i; ++i) {
        fprintf(fout, "\tconst%d dq %lf\n", i, label_arr[i]);
    }

    fprintf(fout, "\nsection .text\n");
    fprintf(fout, "INIT_FPU:\n\tfinit\n\tret\n\n");

    print_asm_func("f1", tree1, fout);
    print_asm_func("f2", tree2, fout);
    print_asm_func("f3", tree3, fout);

}

int fill_label_arr(int i, double *label_arr, Node *tree) {
    if (!tree) { return i; }
    if (tree->token == T_CONST) {
        tree->token = T_LABEL;
        label_arr[i] = tree->constant;
        tree->label_num = i;
        ++i;
    } else if (tree->token == T_E) {
        tree->token = T_LABEL;
        label_arr[i] = EULER;
        tree->label_num = i;
        ++i;
    }
    i = fill_label_arr(i, label_arr, tree->left);
    i = fill_label_arr(i, label_arr, tree->right);
    return i;
}

void print_asm_func(const char *name, Node *tree, FILE *fout) {
    fprintf(fout, "%s:\n", name);
    fprintf(fout, "\tpush ebp\n");
    fprintf(fout, "\tmov ebp, esp\n");
    print_asm_node(tree, fout);
    fprintf(fout, "\tfld qword[esp]\n");
    fprintf(fout, "\tmov esp, ebp\n");
    fprintf(fout, "\tpop ebp\n");
    fprintf(fout, "\tret\n\n");
}

void print_asm_node(Node *tree, FILE *fout) {
    if (!tree) { return; }
    print_asm_node(tree->left, fout);
    print_asm_node(tree->right, fout);
    if (tree->token == T_LABEL) {
        fprintf(fout, "\tfld qword[const%d]\n", tree->label_num);
        fprintf(fout, "\tsub esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_PI) {
        fprintf(fout, "\tfldpi\n");
        fprintf(fout, "\tsub esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_X) {
        fprintf(fout, "\tfld qword[ebp + 8]\n");
        fprintf(fout, "\tsub esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_SIN) {
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfsin\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_COS) {
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfcos\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_TAN) {
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfsin\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfcos\n");
        fprintf(fout, "\tfdivp\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_CTG) {
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfsin\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfcos\n");
        fprintf(fout, "\tfdivp\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_ADD) {
        fprintf(fout, "\tfld qword[esp + 8]\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfaddp\n");
        fprintf(fout, "\tadd esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_SUB) {
        fprintf(fout, "\tfld qword[esp + 8]\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfsubp\n");
        fprintf(fout, "\tadd esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_MUL) {
        fprintf(fout, "\tfld qword[esp + 8]\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfmulp\n");
        fprintf(fout, "\tadd esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } else if (tree->token == T_DIV) {
        fprintf(fout, "\tfld qword[esp + 8]\n");
        fprintf(fout, "\tfld qword[esp]\n");
        fprintf(fout, "\tfdivp\n");
        fprintf(fout, "\tadd esp, 8\n");
        fprintf(fout, "\tfstp qword[esp]\n");
    } 
}