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
    char value[50];
    Node nodeList[20];
    fp = fopen("basic.ntwk", "r");

    // Check file opened correctly
    if ((fp == NULL))
    {
        perror("Error opening file");
        exit(1);
    }
    for(i; i < 20; i++)
    {
    buildNode(nodeList, buffer, fp);
    printf("%s", nodeList);
    }

    
    free(nodeList->conList);
    fclose(fp);
    return 0;
}
