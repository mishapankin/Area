#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

#include <stdio.h>

enum Token;
struct Node;

typedef enum Token Token;
typedef struct Node Node;

enum Token {
    ADD, SUB, DIV, MUL, SIN, COS, TAN, CTG, CONST, X, E, PI
};

struct Node{
    Token token;
    double constant;
    Node *left, *right;
};

int read_node(Node* node, const char *str);
Node* parse_string(const char* str);

int arg_count(Token t);
void print_tree(FILE *fout, Node *n, int parentheses);

#endif // _EXPR_TREE_H_