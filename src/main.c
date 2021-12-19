/*
 * Author: Matheus Amorim Constancio
 *
 * AVL balanced tree implementation
 */

#include <time.h>

#include "avl.h"

#define NUMBER_NODES 10

void usage()
{
    printf("./avl <FILENAME>\n");
}

int main(int argc, char *argv[])
{
    time_t seed = time(0);
    Node *root = NULL;

    FILE *file = fopen("avl.dot", "w");

    if (file == NULL) {
        printf("File not open\n");
        return 1;
    }

    srand(seed);

    for (int i = 0; i < NUMBER_NODES; i++)
        insert_node(&root, rand() % 1000);

    dot_fmt(file, root);

    return 0;
}
