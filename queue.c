#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QUEUE_LENGTH 10

int queue[QUEUE_LENGTH];
int num_of_elements = 0;



bool append(int num)
{
  if(num_of_elements == QUEUE_LENGTH)
  {
    return false; // no space to add
  }
  else
  {
    for(int i = 0; i < num_of_elements; i++)
    {
      queue[i+1] = queue[i];
    }
    queue[0] = num;
    num_of_elements++;
    return true;
  }
}

int del()
{
  if(num_of_elements == 0)
  {
    return 0;
  }
  num_of_elements--;
  return queue[num_of_elements];
}

void print_queue()
{
  for(int i = 0; i < num_of_elements; i++)
  {
    printf("%d, ", queue[i]);
  }
}

int main()
{

  append(10);
  append(5);
  append(2);
  append(-3);

  print_queue();

  del();
  del();
  del();

  printf("\n");

  print_queue();
  
  return 0;
}