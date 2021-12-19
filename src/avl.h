#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    int height;
    Node *left;
    Node *right;
};

Node *new_node(int value);
Node *lowest_node(Node *root);
Node *find_node(Node *root, int value);
void insert_node(Node **root, int value);
Node *remove_node(Node *root, int value);
int greatest_int(int a, int b);
int tree_height(Node *root);
void print_tree(Node *root, int level);

void dot_fmt_null(FILE *file, int value, int count);
void dot_fmt_mid(FILE *file, Node *node);
void dot_fmt(FILE *file, Node *root);
