#include <stdio.h>
#include <stdlib.h>

typedef struct Sides {
    int a, b, c;
}Sides;

int main()
{
    int capacity = 10;
    Sides *data = (Sides*)malloc(capacity* sizeof(Sides));
    int counter = 0;
    int a,b,c = 0;
    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        data[counter].a = a;
        data[counter].b = b;
        data[counter].c = c;
        counter++;
        if (counter == capacity)
        {
            capacity += 10;
            data = (Sides*)realloc(data, capacity* sizeof(Sides));
        }

    }
    int sum = 0;
    for (int i =counter - 1 ; i >= 0; --i)
    {
        printf("%d %d %d\n", data[i].a, data[i].b, data[i].c);
        sum += data[i].a;
        sum += data[i].b;
        sum += data[i].c;
    }
    printf("sum = %d\n", sum);
    free(data);
    return 0;
}
