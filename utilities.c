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
    (buffLen <= 0) ? buffer = 0 : printf("Your input is %d over the maximum size of %d\n", buffLen, size);

    return buffLen;
}