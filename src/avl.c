#include "avl.h"

Node *new_node(int value)
{
    Node *aux;
    aux = malloc(sizeof(struct Node));
    assert(aux);
    aux->value = value;
    aux->height = 0;
    //aux->parent = NULL;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
}

Node *find_node(Node *root, int value)
{
    Node *aux = NULL;

    if (root == NULL)
        aux = NULL;
    else if (value > root->value)
        aux = find_node(root->right, value);
    else if (value < root->value)
        aux = find_node(root->left, value);
    else if (value == root->value)
        aux = root;

    return aux;
}

void insert_node(Node **root, int value)
{
    if (*root == NULL) {
        *root = new_node(value);
        return;
    } else {
        if (value == (*root)->value)
            return;
        else if (value < (*root)->value)
            insert_node(&(*root)->left, value);
        else if (value > (*root)->value)
            insert_node(&(*root)->right, value);
    }
}

void print_tree(Node *root, int level)
{
    Node *aux = root;

    if (aux == NULL) {
        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("NULL\n");
        return;
    }

    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d\n", root->value);
    print_tree(root->left, level + 1);
}

void dot_fmt_null(FILE *file, int value, int count)
{
    fprintf(file, "    NULL%d [label=\"NULL\"];\n", count);
    fprintf(file, "    NULL%d [shape=plaintext];\n", count);
    fprintf(file, "    %d -> NULL%d;\n", value, count);
}

void dot_fmt_mid(FILE *file, Node *node)
{
    static int nullcount = 0;

    if (node->left) {
        fprintf(file, "    %d -> %d;\n", node->value, node->left->value);
        dot_fmt_mid(file, node->left);
    } else {
        dot_fmt_null(file, node->value, nullcount++);
    }

    if (node->right) {
        fprintf(file, "    %d -> %d;\n", node->value, node->right->value);
        dot_fmt_mid(file, node->right);
    } else {
        dot_fmt_null(file, node->value, nullcount++);
    }
}

void dot_fmt(FILE *file, Node *root)
{
    fprintf(file, "digraph AVL {\n");
    fprintf(file, "    node [fontname=\"Arial\"];\n");
    fprintf(file, "    %d;\n", root->value);
    dot_fmt_mid(file, root);

    fprintf(file, "}\n");
}
