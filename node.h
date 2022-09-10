#ifndef _node_h
#define _node_h
// #include "utilities.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Node
{
    int nodeID;
    int conCount;
    int *conList;
} Node;

void buildNode(Node *nodeList, char buffer[], FILE *fp);
// typedef struct Input
// {
//     char cmdarg = 'x';

//     switch(cmdarg)
//     {
//     case '-h':
//         printf("This is the help");
//         break;

//     default:
//         break;
//     }

// }input;

#endif