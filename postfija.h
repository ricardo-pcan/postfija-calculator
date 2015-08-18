#include "pila.h"
#include "pila_operadores.h"
#include "pila_operandos.h"


void convert( char *expresion )
{
  stack infija = NULL, postfija = NULL, aux_p, aux_res;
  int stack_int[100];
  // get postfija
  char *token = strtok( expresion, " ");
  while ( token != NULL )
  {
    insert( &infija, token );
    token = strtok( NULL, " " );
  }

  // convert

  for ( aux_p = infija; aux_p != NULL; aux_p = aux_p -> right )
  {
    if ( isNum ( aux_p -> text ) )
    {
      insert(&postfija, aux_p -> text);
      printf("%s is num\n", aux_p -> text );
    }

    else
    {
      //vacia la pila con )
      if(strcmp(aux_p -> text, ")") == 0 )
      {
        // que no sea ( ni vacia
        while ( strcmp ( get(), "(") != 0 && !isEmpty() )
        {
          insert(&postfija, get() );
          pop();
        }
        pop(); // borramos parentesis y dejamos vacia la pila
      }
      else
      {
        if (isEmpty())
        {
          push(aux_p->text, getPriorityOf(aux_p->text));
        }
        else
        {
          if ( getPriorityOf(aux_p->text) > getPriorityFull() )
          {
            push(aux_p->text, getPriorityOf(aux_p->text));
          }
          else
          {
            if (getPriorityOf(aux_p->text) < getPriorityFull())
            {
              while(!isEmpty())
              {
                insert(&postfija, get());
                pop();
              }
              push(aux_p->text, getPriorityOf(aux_p->text));
            }
            else
            {
              insert(&postfija, get());
              pop();
              push(aux_p->text, getPriorityOf(aux_p->text));
            }  
          } 
        }
      }
    }
  }

  while(!isEmpty())
  {
    insert(&postfija, get());
    pop();
  }

  print(infija);
  print(postfija);

  // results
  int res = 0;
  for ( aux_res = postfija; aux_res != NULL; aux_res = aux_res -> right )
  {
    if (isNum(aux_res->text))
    {
      float z = atof(aux_res->text);
      push_op(z);
    }
    else
    {
      if (strcmp(aux_res->text, "+") == 0 )
      {
        float b =  get_op();
        pop_op();
        float a = get_op();
        pop_op();
        float c = a + b;
        push_op( c );
      }
      else
      {
        if(strcmp(aux_res->text, "-") == 0)
        {
          float b =  get_op();
          pop_op();
          float a = get_op();
          pop_op();
          float c = a - b;
          push_op( c );

        }
        else
        {
          if(strcmp(aux_res->text, "/") == 0)
          {
              float b =  get_op();
              pop_op();
              float a = get_op();
              pop_op();
              float c = a / b;
              push_op( c );
          }
          else
          {
            if(strcmp(aux_res->text, "*") == 0)
            {
                float b =  get_op();
                pop_op();
                float a = get_op();
                pop_op();
                float c = a * b;
                push_op( c );
            }
            else
            {
              float b =  get_op();
              pop_op();
              float a = get_op();
              pop_op();
              float c = pow(a, b);
              push_op( c );
            }
          }
        }
      }
    }
  }

  printf("\n Result: %d", get_op());

  empty(&infija);
  empty(&postfija);
}

/* Regresa la prioridad del operador op */
int getPriorityOf( char *op ){
  if( strcmp( op, "^" ) == 0 ) return 3;
  if( strcmp( op, "*" ) == 0 ) return 2;
  if( strcmp( op, "/" ) == 0 ) return 2;
  if( strcmp( op, "+" ) == 0 ) return 1;
  if( strcmp( op, "-" ) == 0 ) return 1;
  if( strcmp( op, "(" ) == 0 ) return 0;
  if( strcmp( op, ")" ) == 0 ) return 0;
  return -1;
}

/* Regresa verdadero si la cadena n es un numero entero o flotante */
int isNum( char *n ){
  if( strcmp( n, "+" ) != 0 && strcmp( n, ")" ) != 0 && strcmp( n, "-" ) != 0 && strcmp( n, "/" ) != 0 && strcmp( n, "*" ) != 0 && strcmp( n, "^" ) != 0 && strcmp( n, "(" ) != 0 ){
    return 1;
  }else{
    return 0;
  }
}