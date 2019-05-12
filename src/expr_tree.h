#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

enum Token;
struct Node;

typedef enum Token Token;
typedef struct Node Node;

enum Token {
    ADD, SUB, DIV, MUL, SIN, COS, TAN, CTG, CONST, X
};

struct Node{
    Token t;
    double constant;
    Node *l, *r;
};



#endif // _EXPR_TREE_H_