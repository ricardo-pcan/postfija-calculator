#include <stdlib.h>
#include <string.h>

struct node
{
  char text[20];
  struct node *left;
  struct node *right;
};

typedef struct node *stack;
stack g_list = NULL;

void insert (stack *list, char *token)
{
  stack aux;
  stack new_node = ( stack ) malloc (sizeof ( struct node ) );
  strcpy(new_node -> text, token);
  if( *list == NULL )
  {
    *list = new_node;
    (*list) -> right = NULL;
  }
  else
  {
    for(aux = *list; aux -> right != NULL; aux = aux -> right);
    aux -> right = new_node;
    new_node -> left = aux;
    new_node -> right = NULL;
  }
  (*list) -> left = NULL;
}

void drop(stack *list)
{
  if( g_list = *list )
  {
    *list = (*list) -> right;
    if ( *list != NULL ) (*list) -> left = NULL; // only
  }
  else
  {
    if( g_list -> right == NULL )
    {
      g_list -> left -> right = NULL; // last
    }
    else
    {
      g_list -> left -> right = g_list -> right;
      g_list -> right -> left = g_list -> left; // middle
    }
  }

  free( g_list );
}

void empty(stack *list)
{
  stack aux = *list;
  while( aux != NULL )
  {
    g_list = aux;
    aux = aux -> right;
    drop( list );
  }
}

void print(stack list)
{
  for (g_list = list; g_list != NULL; g_list = g_list -> right)
  {
    printf("%s", g_list -> text);
  }
}
