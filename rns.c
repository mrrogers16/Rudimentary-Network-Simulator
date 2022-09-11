#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#define BUFF_SIZE 1024
#define COMMENT_MARKER '#'

int main(int argc, char *argv[])
{

    int i = 0;
    FILE *fp = NULL;
    char buffer[BUFF_SIZE];
    Node nodeList[20];
    fp = fopen("basic.ntwk", "r");

    // Check file opened correctly
    if ((fp == NULL))
    {
        perror("Error opening file");
        exit(1);
    }

    buildNode(nodeList, buffer, fp);

    free(nodeList->conList);
    fclose(fp);
    return 0;
}
