
#define BUFF_SIZE 1024
#define COMMENT_MARKER '#'

int checkString(char buffer[BUFF_SIZE], int size)
{
    int buffLen = (int)strlen(buffer) - size;
    (buffLen <= 0) ? buffer = 0 : printf("Your input is %d over the maximum size of %d\n", buffLen, size);
    
    return buffLen;
}

void stripComment(char* buffer, int bufferSize)
{
    if((buffer == NULL) || (bufferSize == 0))
    {
        printf("DEBUG CODE: parameters are\nbuffer: [NULL]\nsize:[0]");

        return;
    }
    printf("DEBUG CODE: parameters are\nbuffer: [%s]\nsize: [%d]\n", buffer, bufferSize);

    char* comment = strchr(buffer, COMMENT_MARKER);
    if(comment != NULL)
    {
        size_t len = strlen(comment);
        memset(comment, '\0', len);

        printf("DEBUG CODE: buffer = [");
        if(strlen(buffer) == 0)
        {
            printf("NULL]\n");
        }
        else
        {
            printf("%s]\n", buffer);
        }
    }

}

void trim(char *s)
{
    int i = (strlen(s) - 1);
    while (i > 0)
    {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            i--;
        else
            break;
    }
    s[i + 1] = '\0';
}