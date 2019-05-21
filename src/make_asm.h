#ifndef _MAKE_ASM_H_
#define _MAKE_ASM_H_

#include "expr_tree.h"

/// Строит ассемлерный файл fout.
/// В секции .rodata размещены переменные a и b.
/// В секции .text функции f1, f2, f3.
void make_asm(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout);

/// Заполняет массив label_arr значениями констант в дереве tree
/// в порядке обхода в глубину (текущая вершина, левое поддерево, правое).
/// Значение token константной вершины становится равным T_LABEL.
/// Значение label_num становится равным ее номеру в массиве label_arr.
int fill_label_arr(int i, double *label_arr, Node *tree);

/// Добавляет в конец fout ассемблерный код функции с названием name
/// и вычисляющую выражение tree.
void print_asm_func(const char *name, Node *tree, FILE *fout);

/// Печатает в конец fout ассемблерный код, вычисляющий выражение tree.
void print_asm_node(Node *tree, FILE *fout);

#endif // _MAKE_ASM_H_