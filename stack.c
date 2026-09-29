#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define ELEMENT_NUM 10
int top = 0;


int stack[ELEMENT_NUM];

bool push(int value)
{
  if(top >= ELEMENT_NUM)
  {
    return false;
  }
  stack[top] = value;
  top++;
  return true;
}

int pop()
{
  if(top == 0)
  {
    return -1;
  }
  top--;
  return stack[top];
}

void print_stack()
{
  for(int i = 0; i < top; i++)
  {
    printf("%d, ", stack[i]);
  }
}

int main()
{

  push(10);
  push(15);
  push(7);
  push(2);
  push(5);

  print_stack();
  

  return 0;
}