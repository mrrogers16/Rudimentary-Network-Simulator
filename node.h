#ifndef _node_h
#define _node_h
#include "utilities.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int nodeID;
    int conCount;
    int *conList;
} Node;

int checkString(char buffer[], int size);
int checkEndNode(char value[]);
int checkEndNet(char value[]);
void stripComment(char buffer[]);

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