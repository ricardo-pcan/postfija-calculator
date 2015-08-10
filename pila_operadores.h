
struct operadores
{
  char text[20];
  int priority;
  struct operadores *next;
};

typedef struct operadores *stack_op;
stack_op full = NULL;

int isEmpty()
{
  return ( full == NULL ) ? 1 : 0;
}

void push ( char *operador, int priority )
{
  stack_op new_node = (stack_op) malloc ( sizeof ( struct operadores ) );
  new_node -> next = isEmpty() ? NULL : full;
  strcpy( new_node -> text, operador );
  new_node -> priority = priority;
  full = new_node;
}

void pop()
{
  if(!isEmpty())
  {
    stack_op aux = full;
    full = full -> next;
    free( aux );
  }
}

char *get()
{
  return isEmpty() ? "" : full -> text;
}

int getPriorityFull ()
{
  return isEmpty() ? -1 : full -> priority;
}