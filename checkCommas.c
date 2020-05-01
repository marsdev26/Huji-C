int checkPartsList(const char line[1025])
{
    int counter = 0;
    for (int j = 0; line[j] != '\n'; j++)
    {
        if (line[j + 1] == '\n')
        {
            if (line[j] == ',')
            {
                printf("In");
                return EXIT_FAILURE;
            }
            else
            {
                counter++;
                continue;
            }
        }
        if(j == 0 && line[j] != ',')
        {
            counter++;
            continue;
        }
        else if (j == 0 && line[j] == ',')
        {
            return EXIT_FAILURE;
        }
        else if (counter == 1)
        {
            if (line[j] == ',')
            {
                counter = 0;
                continue;
            }
            else
            {
                return EXIT_FAILURE;
            }
        }
        else if (counter == 0)
        {
            if (line[j] == ',')
            {
                return EXIT_FAILURE;
            }
            else
            {
                counter++;
                continue;
            }
        }

    }
    return 0;
}
