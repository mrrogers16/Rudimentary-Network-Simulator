#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024
#define DELIMITER ','

typedef struct simLog
{
    unsigned int start_time;
    char *msg;
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
    int *simCount;
} Log;
int check_columns(char *buffer);
void stripComment(char buffer[]);
void build_sim(Log *simList, char buffer[], FILE *sim);
void printSim(Log *simList);

int main()
{
    FILE *sim = NULL;
    char buffer[BUFFER_SIZE];
    int i;
    sim = fopen("simple.sim", "r");
    Log simList[512];

    if (sim == NULL)
    {
        perror("Error opening file");
    }
    build_sim(simList, buffer, sim);
    
    fclose(sim);
}


void build_sim(Log *simList, char buffer[], FILE *sim)
{
    size_t len = strlen(buffer);
    int cycles = 0;
    char value[50];
    int i = 0;
    while (!feof(sim))
    {
        
        // Read in file line by line
        fgets(buffer, BUFFER_SIZE, sim);
        // Remove comments denoted by '#'
        stripComment(buffer);

        sscanf(buffer, "%u %s %u %u %u", &simList[i].start_time, &simList[i].msg, &simList[i].msg_id, &simList[i].start_node, &simList[i].end_node);
        printf("%u\n%s\n%u\n%u\n%u",&simList[i].start_time, &simList[i].msg, &simList[i].msg_id, &simList[i].start_node, &simList[i].end_node);
    }
}

void stripComment(char buffer[])
{
    char COMMENT_MARKER = '#'; //
    char *comment = strchr(buffer, COMMENT_MARKER);

    if (comment != NULL)
    {
        size_t len = strlen(comment);
        memset(comment, '\0', len);
    }
}


void printSim(Log *simList)
{
    size_t len = strlen(simList);
    for(int i = 0; i < len; i++)
    {
    printf("%u", simList[i].start_time);
    // printf("%s", simList[i].msg);
    // printf("%u", simList[i].msg_id);
    }
}

    // int check_columns(char *buffer)
    // {
    //     size_t len = strlen(buffer);
    //     int i;
    //     int columns = 0;
    //     for (i = 0; i < len; i++)
    //     {
    //         if (buffer[i] == ',')
    //         {
    //             columns += 1;
    //         }
    //         else if (buffer[i] == NULL)
    //         {
    //             break;
    //         }
    //     }
    //     return columns;
    // }
