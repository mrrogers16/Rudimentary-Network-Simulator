
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024

typedef struct simLog
{
    unsigned int start_time;
    char *msg[512];
    unsigned int msg_id;
    unsigned int start_node;
    unsigned int end_node;
    int *simList;
} Log;

int check_columns(char buffer[]);
void build_sim(Log *simList, char buffer[], FILE *sim);
void stripComment(char buffer[]);
int checkString(char buffer[], int size);

int main()
{
    FILE *sim = NULL;
    char buffer[BUFF_SIZE];
    Log simList[100];
    sim = fopen("simple.sim", "r");
    build_sim(simList, buffer, sim);
    //printf("%u\n", simList[0].start_time);
    //printf("%s\n", simList[0].msg);
    fclose(sim);
}

void build_sim(Log *simList, char buffer[], FILE *sim)
{
    while (!feof(sim))
    {
        int i = 0;
        fgets(buffer, BUFF_SIZE, sim);
        checkString(buffer, BUFF_SIZE);
        stripComment(buffer);
        size_t len = strlen(buffer);

        for (i = 0; i < len; i++)
        {
            int columns = check_columns(buffer);
            if (columns == 0)
            {
                printf("Buffer is empty or Columns function failed");
            }
            if (columns == 4)
            {
                sscanf(buffer, "%u,%[^,],%u,%u,%u", &simList[i].start_time, simList[i].msg, &simList[i].msg_id, &simList[i].start_node, &simList[i].end_node);
                printf("Start Time: %u\nMessage: %s\nMessage ID: %u\nStart Node: %u\nEnd Node: %u\n", simList[i].start_time, simList[i].msg, simList[i].msg_id, simList[i].start_node, simList[i].end_node);
                i++;
                break;
            }
            else if (columns == 2)
            {
                sscanf(buffer, "%u,%s,%u", &simList[i].start_time, &simList[i].msg, &simList[i].start_node);
                i++;
                break;
            }
            else if (columns == 1 && strcmp(buffer, "rep") == 0)
            {
                sscanf(buffer, "%u,%s", &simList[i].start_time, &simList[i].msg);
                i++;
                break;
            }
            else if (columns == 1 && strcmp(buffer, "endSim") == 0)
            {
                sscanf(buffer, "%u,%s", &simList[i].start_time, &simList[i].msg);
                i++;
                exit(0);
            }
        }
    }
}

int check_columns(char buffer[])
{
    size_t len = strlen(buffer);
    int i;
    int columns = 0;
    for (i = 0; i < len; i++)
    {
        if (buffer[i] == ',')
        {
            columns += 1;
        }
        else
        {
            continue;
        }
    }
    return columns;
}

void stripComment(char buffer[])
{
    char COMMENT_MARKER = '#';
    char *comment = strchr(buffer, COMMENT_MARKER);

    if (comment != NULL)
    {
        size_t len = strlen(comment);
        memset(comment, '\0', len);
    }
}
int checkString(char buffer[], int size)
{
    int buffLen = (int)strlen(buffer) - size;

    if (buffLen <= 0)
    {
        buffer = 0;
    }
    else
    {
        printf("Your input is %d over the maximum size of %d\n", buffLen, size);
    }
    return buffLen;
}