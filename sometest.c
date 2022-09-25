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
            if (columns == NULL)
            {
                printf("Buffer is empty or Columns function failed");
            }
            if (columns == 4)
            {
                read = fscanf(buffer, "%u,%s,%u,%u,%u", &csvList[i].start_time, &csvList[i].msg, &csvList[i].start_node, &csvList[i].end_node);
                records++;
            }
            else if (columns == 2)
            {
                fscanf(buffer, "%u,%s,%u", &csvList[i].start_time, &csvList[i].msg, &csvList[i].start_node);
                records++;
            }
            else if (columns == 1 && strchr(buffer, 'rep'))
            {
                fscanf(buffer, "%u,%s", [i].start_time, csvList[i].msg);
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