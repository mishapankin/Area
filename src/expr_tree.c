#include "expr_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>


#define MAX_TREE_SIZE 100

int read_node(Node* node, const char *str) {
    int n;
    double cnst;
    if (sscanf(str, "%lf%n", &cnst, &n) == 1) {
        node->token = T_CONST;
        node->constant = cnst;
        return n;
    }

    char buff[4];

    if (sscanf(str, "%s%n", buff, &n) == 1) {
        if (!strcmp(buff, "+")) {
            node->token = T_ADD;
        } else if (!strcmp(buff, "-")) {
            node->token = T_SUB;
        } else if (!strcmp(buff, "*")) {
            node->token = T_MUL;
        } else if (!strcmp(buff, "/")) {
            node->token = T_DIV;
        } else if (!strcmp(buff, "sin")) {
            node->token = T_SIN;
        } else if (!strcmp(buff, "cos")) {
            node->token = T_COS;
        } else if (!strcmp(buff, "tan")) {
            node->token = T_TAN;
        } else if (!strcmp(buff, "ctg")) {
            node->token = T_CTG;
        } else if (!strcmp(buff, "e")) {
            node->token = T_E;
        } else if (!strcmp(buff, "pi")) {
            node->token = T_PI;
        } else if (!strcmp(buff, "x")) {
            node->token = T_X;
        } else {
            return 0;
        }
        return n;
    }
    return 0;
}

Node* parse_string(const char* str) {
    Node* nodes = malloc(MAX_TREE_SIZE * sizeof(Node));
    int cnt = 0;

    int ln = strlen(str);
    for (int shift = 0; shift < ln;) {
        int n = read_node(nodes + cnt, str + shift);
        if (n) {
            ++cnt;
            shift += n;
        } else { break; }
    }
    nodes = realloc(nodes, cnt * sizeof(Node));

    Node **stack = malloc(cnt * sizeof(Node));
    Node **stack_top = stack;

    for (int i = 0; i < cnt; ++i) {
        nodes[i].left = NULL;
        nodes[i].right = NULL;
        if (arg_count(nodes[i].token) == 0) {
            ++stack_top;
        }
        if (arg_count(nodes[i].token) == 1) {
            nodes[i].left = *stack_top;
        }
        if (arg_count(nodes[i].token) == 2) {
            nodes[i].left = *(stack_top - 1);
            nodes[i].right = *stack_top;
            --stack_top;
        }
        *stack_top = &nodes[i];
    }

    return *stack_top;
}

int arg_count(Token t) {
    if (t == T_CONST || t == T_X || t == T_E || t == T_PI) { return 0; }
    if (t == T_SIN || t == T_COS || t == T_TAN || t == T_CTG) { return 1; }
    return 2;
}

void print_tree(FILE *fout, Node *n, int parentheses) {
    if (!n) { return; }
    if (parentheses) {
        fprintf(fout, "(");
    }
    if (arg_count(n->token) == 0) {
        switch (n->token) {
        case T_CONST:
            fprintf(fout, "%lf", n->constant);
            break;
        case T_X:
            fprintf(fout, "x");
            break;
        case T_E:
            fprintf(fout, "e");
        case T_PI:
            fprintf(fout, "pi");
        default:
            break;
        }
        if (!parentheses) { fprintf(fout, " "); }
    } else if (arg_count(n->token) == 1) {
        switch (n->token) {
        case T_SIN:
            fprintf(fout, "sin");
            break;
        case T_COS:
            fprintf(fout, "cos");
            break;
        case T_TAN:
            fprintf(fout, "tan");
            break;
        case T_CTG:
            fprintf(fout, "ctg");
            break;
        default:
            break;
        }
        print_tree(fout, n->left, 1);
    } else {
        int par = n->token == T_DIV || n->token == T_MUL;
        print_tree(fout, n->left, par);

        switch (n->token) {
        case T_ADD:
            fprintf(fout, "+ ");
            break;
        case T_SUB:
            fprintf(fout, "- ");
            break;
        case T_DIV:
            fprintf(fout, "/ ");
            break;
        case T_MUL:
            fprintf(fout, "* ");
            break;
        default:
            break;
        }
        print_tree(fout, n->right, par);
    }
    if (parentheses) {
        fprintf(fout, ") ");
    }
}