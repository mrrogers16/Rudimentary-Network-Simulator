#include "utilities.h"
#include "node.h"
#define COMMENT_MARKER '#'
#define BUFF_SIZE 1024

int checkEndNet(char value[])
{
    if (strcmp(value, "endNet") == 0)
    {
        printf("Found endNet\n");
        return 0;
    }
}

int checkEndNode(char value[])
{
    if (strcmp(value, "endNode") == 0)
    {
        printf("Found endnode\n");
        return 0;
    }
}

void buildNode(Node *nodeList, char buffer[], FILE *fp)
{

    char value[50];
    int i = 0;
    while (!feof(fp))
    {

        fgets(buffer, BUFF_SIZE, fp);

        // Handle oversized buffer
        checkString(buffer, BUFF_SIZE);

        // Remove comments
        stripComment(buffer);

        // memory address at s is set when ',' is found
        char *s = strchr(buffer, ',');
        if (s != NULL)
        {
            // Scan the buffer to look for comma and if found assign NodeID and connection count to memory addressd of nodeList[i]
            sscanf(buffer, "%d, %d", &nodeList[i].nodeID, &nodeList[i].conCount);
            printf("Found nodeId: %d\nFound Connection Count of: %d\n", nodeList[i].nodeID, nodeList[i].conCount);
            // dynamically allocate memory for conList
            nodeList->conList = (int *)malloc(sizeof(int) * nodeList[i].conCount);

            // Look through buffer conCount amount of times and assign
            int x, j = 0;
            for (x = 0; x < nodeList->conCount; x++)
            {
                for (j; j < nodeList[i].conCount; j++)
                {

                    fgets(buffer, BUFF_SIZE, fp);
                    if (buffer[0] == COMMENT_MARKER)
                    {
                        j -= 1;
                        continue;
                    }
                    sscanf(buffer, "%d", &nodeList->conList[j]);
                    printf("Connection %d: %d\n", x, nodeList->conList[j]);
                    x++;
                }
            }
            continue;

            sscanf(buffer, "%s", value);
            if (checkEndNode(value) == 0)
            {
                i++;
                continue;
            }
            checkEndNet(value);
        }
    }
}
