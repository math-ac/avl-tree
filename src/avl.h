#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    int height;
    //Node *parent;
    Node *left;
    Node *right;
};

Node *new_node(int value);
Node *find_node(Node *root, int value);
void insert_node(Node **root, int value);
void print_tree(Node *root, int level);
int tree_height(Node *root);

void dot_fmt_null(FILE *file, int value, int count);
void dot_fmt_mid(FILE *file, Node *node);
void dot_fmt(FILE *file, Node *root);
