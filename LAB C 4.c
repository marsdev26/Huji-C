typedef struct Sides {
    int a, b, c;
}Sides;

int main()
{
    int capacity = 10;
    Sides *data = (Sides*)malloc(capacity* sizeof(Sides));
    int arr[3];
    int counter = 0;
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        data[counter].a =a;
        data[counter].b = b;
        data[counter].c = c;
        counter += 1;
        if (counter == 10)
        {
            capacity += 10;
            data = (Sides*)malloc(capacity* sizeof(Sides));
        }

    }
    int sum = 0;
    for (int i =0; i < counter; i++)
    {
        printf("%d %d %d", data[i].a, data[i].b, data[i].c);
        sum += data[i].a;
        sum += data[i].b;
        sum += data[i].c;
    }
    printf("%d", sum);
    return 0;
}
