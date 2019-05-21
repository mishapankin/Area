#ifndef _MAKE_JS_H_
#define _MAKE_JS_H_

#include <stdio.h>

#include "expr_tree.h"

/// Печатает в файл fout javascript код, содержащий константы a и b 
/// и выражения tree1, tree2, tree3.
void make_js(double a, double b, Node *tree1, Node *tree2, Node *tree3, FILE *fout);

#endif // _MAKE_JS_H_