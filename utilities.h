#ifndef _UTILITIES_H
#define _UTILITIES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



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
#endif