#include "avl.h"

Node *new_node(int value)
{
    Node *aux;
    aux = malloc(sizeof(struct Node));
    assert(aux);
    aux->value = value;
    aux->height = 0;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
}

Node *lowest_node(Node *root)
{
    Node *aux = root;

    while (aux->left != NULL)
        aux = aux->left;

    return aux;
}

Node *find_node(Node *root, int value)
{
    Node *aux = NULL;

    if (root == NULL)
        aux = NULL;
    else if (value < root->value)
        aux = find_node(root->left, value);
    else if (value > root->value)
        aux = find_node(root->right, value);
    else if (value == root->value)
        aux = root;

    return aux;
}

void insert_node(Node **root, int value)
{
    if (*root == NULL) {
        *root = new_node(value);
        return;
    } else if (value < (*root)->value) {
        insert_node(&(*root)->left, value);
    } else if (value > (*root)->value) {
        insert_node(&(*root)->right, value);
    } else if (value == (*root)->value) {
        return;
    }
}

Node *remove_node(Node *root, int value)
{
    if (root == NULL) {
        return NULL;
    } else if (value < root->value) {
        root->left = remove_node(root->left, value);
    } else if (value > root->value) {
        root->right = remove_node(root->right, value);
    } else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left) {
            Node *tmp = root->right;
            free(root);
            return tmp;
        } else if (!root->right) {
            Node *tmp = root->left;
            free(root);
            return tmp;
        } else {
            Node *tmp = lowest_node(root->right);
            root->value = tmp->value;
            root->right = remove_node(root->right, tmp->value);
        }
    }

    return root;
}

int greatest_int(int a, int b)
{
    return (a > b) ? a : b;
}

int tree_height(Node *root)
{
    int height = 0;
    int h_left = 0, h_right = 0;

    if (root == NULL) {
        height = -1;
    } else {
        h_left = tree_height(root->left) + 1;
        h_right = tree_height(root->right) + 1;
        height = greatest_int(h_left, h_right);
    }

    return height;
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
