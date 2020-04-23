typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;  // The head of the list - global


void push(int d) {
    Node* newNode = malloc(sizeof(Node));
    (*newNode).data = d;
    (*newNode).next = head;
    head = newNode;

}

void deleteList() {
    while (head != NULL)
    {
        free(head);
        head = (*head).next;
        head = NULL;
    }
}

void printList() {
    while (head != NULL)
    {
        printf("%d ",(*head).data);
        head = head->next;
    }
    printf("\n");
}
