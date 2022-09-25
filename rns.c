#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "node.h"
#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{

    FILE *fp = NULL;
    FILE *sim = NULL;
    char buffer[BUFF_SIZE];
    Node nodeList[20];
    Log csvList[100];
    fp = fopen(argv[2], "r");
    sim = fopen(argv[4], "r");
    int opt;

    parseCMDLine(argc, argv);

    while ((opt = getopt(argc, argv, ":hsn:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            if (fp == NULL)
            {
                perror("Error opening file");
                exit(1);
            }
            else
            {
                buildNode(nodeList, buffer, fp);
                // printBuffer(buffer);
            }
            break;
        case 's':
            if (fp == NULL)
            {
                perror("Error opening file");
                exit(1);
            }
            else
            {
                build_csv(csvList, buffer, sim);
            }
            break;
        case 'h':
            printHelp();
            return 0;

        case '?':
            fprintf(stderr, "Unrecognized option -%c\n", optopt);
            return 0;

        default:
            printHelp();
            return 0;
        }
    }

    free(nodeList->conList);
    fclose(sim);
    fclose(fp);
    return 0;
}
