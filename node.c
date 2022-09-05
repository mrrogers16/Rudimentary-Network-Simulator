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
    //
    if ((fp == NULL))
    {
        perror("Error opening file");
        exit(1);
    }

    while (!feof(fp))
    {
        fgets(buffer, BUFF_SIZE, fp);
        char *comment = strchr(buffer, COMMENT_MARKER);
        if (comment != NULL)
        {
            size_t len = strlen(comment);
            memset(comment, '\0', len);
        }

        char *s = strchr(buffer, ',');

        if (s != NULL)
        {
            sscanf(buffer, "%d, %d", &nodeList[i].nodeID, &nodeList[i].conCount);
            printf("Found nodeId: %d\nFound Connection Count of: %d\n", nodeList[i].nodeID, nodeList[i].conCount);
            nodeList->conList = (int *)malloc(sizeof(int) * nodeList[i].conCount);
            int j = 0;
            for (j; j < nodeList[i].conCount; j++)
            {
                fgets(buffer, BUFF_SIZE, fp);
                sscanf(buffer, "%d", &nodeList->conList[j]);
                printf("connect node: %d\n", nodeList->conList[j]);
            }
            continue;
        }

        // sscanf(buffer, "%d, %d", &nodeList[i].nodeID, &nodeList[i].conCount);

        sscanf(buffer, "%s", value);

        if (strcmp(value, "endNode") == 0)
        {
            printf("Found endnode\n");
            i++;
            continue;
        }
        if (strcmp(value, "endNet") == 0)
        {
            printf("Found endNet\n");
            return 0;
        }
    }
    fclose(fp);
    return 0;
}
