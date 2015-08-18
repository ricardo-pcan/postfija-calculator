
struct operandos
{
  float number;
  struct operandos *next;
};

typedef struct operandos *stack_opr;
stack_opr full_opr = NULL;

int isEmpty_op()
{
  return ( full_opr == NULL ) ? 1 : 0;
}

void push_op ( float operador )
{
  stack_opr new_node = (stack_opr) malloc ( sizeof ( struct operandos ) );
  new_node -> next = isEmpty_op() ? NULL : full_opr;
  new_node -> number = operador;
  full_opr = new_node;
}

void pop_op()
{
  if(!isEmpty_op())
  {
    stack_opr aux = full_opr;
    full_opr = full_opr -> next;
    free( aux );
  }
}

int get_op()
{
  return isEmpty_op() ? -1 : full_opr -> number;
}
