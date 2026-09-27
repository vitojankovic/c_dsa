#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int value;
  struct Node *next;
};

struct Node *create_linked_list()
{
  printf("Enter how many nodes you wanna have: ");
  int i;
  scanf("%d", &i);
  struct Node *head = malloc(sizeof(struct Node));

  printf("Enter value of node number 0: ");
  scanf("%d", &head->value);
  head->next = NULL;

  struct Node *current;
  current = head;

  for(int j = 0; j < (i-1); j++)
  {
    struct Node *newNode = malloc(sizeof(struct Node));

    printf("Enter value of the node number %d: ", j+1);
    scanf("%d", &newNode->value);
    newNode->next = NULL;

    current->next = newNode;
    current = newNode;
  }

  return head;
}

void print_list(struct Node *head)
{
  //TODO: print a linked list
  //? First get the head value
  //? Since linked_list is a pointer to the first node/value just print it
  //? create the current node just for structure
  //? while current->next != NULL
  //? print current->value
  printf("%d \n", head->value);

  struct Node *current;
  current = head;

  while(current->next != NULL)
  {
    current = current->next;
    printf("%d \n", current->value);
  }
}

int list_length(struct Node *head)
{
  //TODO: walk through the list and keep a counter
  int counter = 1;

  struct Node *current = head;

  while(current->next != NULL)
  {
    counter++;
    current = current->next;
  }

  return counter;
}

struct Node *find_node(struct Node *head, int target)
{
  //TODO: walk through the linked list until the current->value != target, when it is, return it
  struct Node *current = head;

  while(current->next != NULL)
  {
    if(current->value == target)
    {
      return current;
    }
    else{
      current = current->next;
    }
  }

  return NULL;

}

void push_front(struct Node **head, int value)
{
  //TODO: push a value to the front of the list
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->next = *head;
  *head=newNode;
}

void push_back(struct Node **head, int value)
{
  //TODO: loop the entire linked list to find the end ( node that points to null ) and make it point at newNode
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->next = NULL;

  if(*head == NULL)
  {
    //? Empty list
    *head= newNode;
    return;
  }

  struct Node *current = *head;


  while(current->next != NULL)
  {
    current=current->next;
  }
  current->next = newNode;
}

void delete_value(struct Node **head, int target)
{
  //TODO: remove the first node matching value and free it
  //IF the node im deleting is a head, then the next node becomes the head
  //BUT if its not the head, i have to go one step back and change the previous's node's next to the one after the one i deleted
  //IF the node is the tail, then go back and set the previous nodes next to null
  

  struct Node *current = *head;
  struct Node *previous = NULL;

  while(current != NULL)
  {
    if(current->value == target)
    {
      // perform deletion
      if(previous == NULL)
      {
        *head = current->next;
      }
      else
      {
        previous->next = current->next;
      }
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

}

struct Node *reverse_list(struct Node *head)
{
  //TODO: reverse list
  // GOTO last first and set its next to the one before and set it to head
  // use 2 variables current and previous
  struct Node *current = head;
  struct Node *prev = NULL;

  // better idea: in a loop skip one each time, so 2's increment and then when land on current previous is prev= next is next=current->next
  while(current != NULL)
  {
    // sets variables 
    struct Node *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

int main()
{
  struct Node *list = create_linked_list();
  // print_list(list);
  // int list_len = list_length(list);
  // struct Node *find_me = find_node(list, 5);
  // printf("%p", find_me);


  push_front(&list, 7);


  push_back(&list, 99);

  list = reverse_list(list);

  print_list(list);

}