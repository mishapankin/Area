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

Node* alloc_tree(Node *tree);
void free_tree(Node *tree);
void optimize_constexpr(Node *tree);

int read_node(Node* node, const char *str);
Node* parse_string(const char* str);

int arg_count(Token t);
void print_tree(FILE *fout, Node *n, int parentheses);

#endif // _EXPR_TREE_H_