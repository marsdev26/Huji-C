int algorithm(int ** a, RoadParts *parts, char algInParts[MAX_LENGTH_LINE],
              long numRoadLength, int numRoadParts, long numInitialParts)
{
    int min = INT_MAX;
    int min_price = 0;
    int temp;

    assignIndex(parts, numRoadParts, algInParts, numInitialParts);

    for (int m = 0; m < (int)numRoadLength + 1; m++)
    {
        for (int r = 0; r < (int)numInitialParts; r++)
        {
            a[m][r] = INT_MAX;
        }
    }

    for (int i = 0; i < (int)numRoadLength + 1; i++ )
    {
        for (int k = 0; k < (int)numInitialParts; k++)
        {
            if (i == 0)
            {
                a[i][k] = 0;
                continue;
            }
            min = findMin(numRoadParts, a, parts, k, i, algInParts, min_price, min);
            a[i][k] = min;
            min = INT_MAX;
        }
    }


    for(int l = 0; l < (int)numInitialParts; l++)
    {
            temp = a[(int) numRoadLength][l];
            if (temp < min)
            {
                min = temp;
            }
            else
            {
                continue;
            }
    }

    if (min == INT_MAX)
    {
        min = -1;
    }

    return min;
}
