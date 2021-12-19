/*
 * Author: Matheus Amorim Constancio
 *
 * AVL balanced tree implementation
 */

#include "avl.h"

void usage()
{
    printf("./avl <FILENAME>\n");
}

int main(int argc, char *argv[])
{
    Node *root = NULL;
    FILE *file = fopen("avl.dot", "w");

    if (file == NULL) {
        printf("File not open\n");
        return 1;
    }

    insert_node(&root, 5);
    insert_node(&root, 7);
    insert_node(&root, 3);
    insert_node(&root, 4);
    insert_node(&root, 10);
    insert_node(&root, 8);
    insert_node(&root, 6);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 30);
    insert_node(&root, 71);
    insert_node(&root, 32);
    insert_node(&root, 41);
    insert_node(&root, 15);
    insert_node(&root, 33);
    insert_node(&root, 27);
    insert_node(&root, 21);
    insert_node(&root, 13);
    insert_node(&root, 0);
    insert_node(&root, 12);

    dot_fmt(file, root);

    printf("The lowest value of a node is %d\n", lowest_node(root)->value);

    FILE *depois = fopen("depois.dot", "w");

    if (depois == NULL) {
        printf("File not open\n");
        return 1;
    }

    remove_node(root, 0);
    remove_node(root, 1);
    printf("The lowest value of a node is %d\n", lowest_node(root)->value);

    dot_fmt(depois, root);

    return 0;
}
