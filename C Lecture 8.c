typedef struct Node
{
  char * _data; // pointer to data
  struct Node * _next;
} Node;

typedef struct Stack
{
  // what should be here?
  Node* _top;
} Stack;

Stack* stackAlloc()
{
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  if (stack != NULL) {
      // init top
      (*stack)._top = NULL;
  }
  return stack;
}

void freeStack(Stack** stack)
{
    Node *p1;
    Node *p2;
    
    if (*stack == NULL)
    {
        return;
    }
    
    p1 = (**stack)._top;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = (*p1)._next;
        free(p2);
    }
    
    free(*stack);
    *stack = NULL;
  
}

void push(Stack* stack, char *data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  if(node != NULL) {
    // update stack    
    (*node)._data = data;
    (*node)._next = (*stack)._top;
    (*stack)._top = node;
  }
}

char* pop(Stack* stack) 
{
  if(stack == NULL || stack->_top == NULL)
    {
      return NULL;
    }

  // pop
  Node* node = (*stack)._top;
  char* ret = (*node)._data;
  (*stack)._top = (*node)._next;
  free(node);
  
  return ret;
}

int isEmptyStack(Stack* stack) 
{
  if(stack != NULL) 
     return stack->_top == NULL;
  // else ???
  return 1;
}
