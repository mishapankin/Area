#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

#include <stdio.h>

enum Token;
struct Node;

typedef enum Token Token;
typedef struct Node Node;

enum Token {
    T_ADD, T_SUB, T_DIV, T_MUL, T_SIN, T_COS, T_TAN, T_CTG, T_CONST, T_X, T_E, T_PI, T_LABEL
};

struct Node{
    Token token;
    union {
        double constant;
        int label_num;
    };
    Node *left, *right;
};

/// Копирует дерево, гарантируя выделение памяти для каждой вершины по-отдельности.
/// Необходимо выполнить для работы free_tree
Node* alloc_tree(Node *tree);

/// Освобождает память.
void free_tree(Node *tree); 

/// Оптимизирует подвыражения на этопе компиляции, если возможно.
/// Также заменяет expr - -const2 на expr + const, если const > 0
void optimize_constexpr(Node *tree);

/// Если дерево является константой, возвращает ее, иначе NAN.
double get_const(Node *tree); 

/// Считывает первый токен из строки str в node.
int read_node(Node* node, const char *str);

/// Строит дерево выражения по str и оптимизирует.
Node* parse_string(const char* str); 

/// Возвращает количество аргументов, принимаемых операцией (0, 1, 2).
int arg_count(Token t);

/// Выводит на поток fout дерево n в инфиксной форме.
/// Если parentheses, то с внешними круглыми скобками.
void print_tree(FILE *fout, Node *n, int parentheses); 

#endif // _EXPR_TREE_H_