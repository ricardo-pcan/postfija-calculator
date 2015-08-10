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
        if (isEmpty() || getPriorityOf(aux_p->text) > getPriorityFull())
        {
          push(aux_p->text, getPriorityOf(aux_p->text));
        }
        else
        {
          if (getPriorityOf(aux_p->text) <getPriorityFull())
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
        /*if (isEmpty())
        {
          push( aux_p->text, getPriorityOf( aux_p -> text ));
        }
        else
        {
          // si operador es menor
          if( getPriorityOf(aux_p -> text) < getPriorityFull() )
          {
            push( aux_p -> text, getPriorityOf(aux_p -> text));
            while(!isEmpty)
            {
              if(strcmp( get(), "(") == 0 )
              {
                pop();
              }
              insert(&postfija, get());
              pop();
            }
          }
          else
          {
            //si el operador es igual
            if ( getPriorityOf(aux_p -> text) == getPriorityFull())
            {
              insert(&postfija, get());
              pop();
              push( aux_p -> text, getPriorityOf(aux_p->text));
            }
            else
            {
              push( aux_p -> text, getPriorityOf(aux_p->text) );
            }
          }
        }*/
      }
    }
  }

  while(!isEmpty())
  {
    insert(&postfija, get());
    pop();
  }

  //print(infija);
  //print(postfija);

  // results
  int res = 0;
  for ( aux_res = postfija; aux_res != NULL; aux_res = aux_res -> right )
  {
    if (isNum(aux_res->text))
    {
      int z = atoi(aux_res->text);
      push_op(z);
    }
    else
    {
      if (strcmp(aux_res->text, "+") == 0 )
      {
        int b =  get_op();
        pop_op();
        int a = get_op();
        pop_op();
        int c = a + b;
        push_op( c );
      }
      else
      {
        if(strcmp(aux_res->text, "-") == 0)
        {
          int b =  get_op();
          pop_op();
          int a = get_op();
          pop_op();
          int c = a - b;
          push_op( c );

        }
        else
        {
          if(strcmp(aux_res->text, "/") == 0)
          {
              int b =  get_op();
              pop_op();
              int a = get_op();
              pop_op();
              int c = a / b;
              push_op( c );
          }
          else
          {
              int b =  get_op();
              pop_op();
              int a = get_op();
              pop_op();
              int c = a * b;
              push_op( c );
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
  if( strstr("*/", op ) != NULL ) return 2; 
  if( strstr("+-", op ) != NULL ) return 1; 
  if( strstr("(", op ) != NULL )  return 0; 
  return -1;
}

/* Regresa verdadero si la cadena n es un numero entero o flotante */
int isNum( char *n ){
  if( strcmp( n, "+" ) != 0 && strcmp( n, "-" ) != 0 && strcmp( n, "/" ) != 0 && strcmp( n, "*" ) != 0 && strcmp( n, "(" ) != 0 && strcmp( n, ")" ) != 0 ){
    return 1;
  }else{
    return 0;
  }
}