/*
 * Author: Matheus Amorim Constancio
 *
 * AVL balanced tree implementation
 */

#include "avl.h"

void usage()
{
    //TODO
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

    random_tree(&root, 10);
    dot_fmt(file, root);

    return 0;
}
