#ifndef _node_h
#define _node_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 512

typedef struct Node
{
    int nodeID;
    int conCount;
    int *conList;
    struct Node *next;
} Node;
typedef struct simLog
{
    unsigned int start_time;
    char *msg[MAX];
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
    int *simList;
} Log;
typedef struct report
{
    unsigned int start_time;
    char *msg[MAX];
    unsigned int selected_node;
    int *repList;
} Rep;
typedef struct route
{
    unsigned int hop_count;
    unsigned int final_destination;
    unsigned int next_hop_node;
} Route;
typedef struct message
{
    unsigned int message_ID;
    unsigned int start_time;
    unsigned int start_node;
    unsigned int end_node;
    unsigned int current_node;
    unsigned int end_time;
    char *message_contents[MAX];
    struct message *next;
    struct message *prev;
} Message;

void buildNode(Node *nodeList, char buffer[], FILE *fp);
void build_sim(Log *simList, Rep *repList, char buffer[], FILE *sim);
void stripComment(char buffer[]);
int checkString(char buffer[], int size);
void parseCMDLine(int argc, char *argv);
int check_columns(char buffer[]);
void printHelp();

#endif
