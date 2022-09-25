#ifndef _node_h
#define _node_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int nodeID;
    int conCount;
    int *conList;
} Node;

typedef struct csvLog
{
    unsigned int start_time;
    char *msg;
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
} Log;

typedef struct csvRep
{
    unsigned int start_time;
    char *rep;
    unsigned int node_ID;
} Rep;

void build_sim(Log *csvList, char buffer[], FILE *csvp);
void buildNode(Node *nodeList, char buffer[], FILE *fp);

#endif
