#include "utilities.h"
#include "node.h"
#define COMMENT_MARKER '#'
#define BUFF_SIZE 1024

void buildNode(Node *nodeList, char buffer[], FILE *fp)
{

    char value[50];
    int i = 0;
    while (!feof(fp))
    {
        // Read in file line by line
        fgets(buffer, BUFF_SIZE, fp);

        // Handle oversized buffer
        checkString(buffer, BUFF_SIZE);

        // Remove comments
        stripComment(buffer);

        // memory address at s is set when ',' is found
        char *s = strchr(buffer, ',');
        if (s != NULL)
        {
            // Scan the buffer to look for comma and if found assign NodeID and connection count to memory address of nodeList[i]
            sscanf(buffer, "%d, %d", &nodeList[i].nodeID, &nodeList[i].conCount);
            printf("Found nodeId: %d\nConnection Count: %d\n", nodeList[i].nodeID, nodeList[i].conCount);
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
        }
        sscanf(buffer, "%s", value);
        if (strcmp(value, "endNode") == 0)
        {
            // printf("Found endnode\n");
            printf("---------------\n");
            continue;
        }

        if (strcmp(value, "endNet") == 0)
        {
            // printf("Found endNet\n");
            exit(0);
        }
    }
}

void build_csv(Log *csvList, char buffer[], FILE *csvp)
{
    char value[50];
    int i = 0;
    unsigned int ts = 0;
    int read = 0;
    int records = 0;

    while (!feof(csvp))
    {
        fgets(buffer, BUFF_SIZE, csvp);
        checkString(buffer, BUFF_SIZE);
        stripComment(buffer);
        int columns = check_columns(buffer);
        size_t len = strlen(buffer);
        for (i = 0; i < len; i++)
        {
            if(columns == NULL)
            {
                printf("Buffer is empty or Columns function failed");
            }
            if (columns == 4)
            {
                read = fscanf(buffer, "%u,%s,%u,%u,%u", &csvList[i].start_time, &csvList[i].msg, &csvList[i].current_node, &csvList[i].end_node);
                records++;
            }
            else if(columns == 2)
            {
                fscanf(buffer, "%u,%s,%u", &csvList[i].start_time, &csvList[i].msg, &csvList[i].current_node);
                records++;
            }
            else if (columns == 1 && strchr(buffer, 'rep'))
            {
                fscanf(buffer, "%u,%s", csvList[i].start_time, csvList[i].msg);
                records++;
            }
            else if (columns == 1 && strchr(buffer, 'endSim'))
            {
                fscanf(buffer, "%u,%s", csvList[i].start_time, csvList[i].msg);
                exit(0);
            }
        }
    }

    sscanf(buffer, "%u,%s", &ts, &value);
    if (strcmp(value, "endSim") == 0)
    {
        exit(0);
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
