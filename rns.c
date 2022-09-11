#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include "node.h"
#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{

    FILE *fp = NULL;
    char buffer[BUFF_SIZE];
    Node nodeList[20];
    fp = fopen(argv[2], "r");
    int opt;

    parseCMDLine(argc, argv);

    while ((opt = getopt(argc, argv, ":hn:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            if ((fp == NULL))
            {
                perror("Error opening file");
                exit(1);
            }
            else
            {
                buildNode(nodeList, buffer, fp);
            }
            break;
        case 'h':
            printHelp();
            break;
        case '?':
            fprintf(stderr, "Unrecognized option -%c\n", optopt);
            break;
        default:
            printHelp();
        }
    }

    free(nodeList->conList);
    fclose(fp);
    return 0;
}
