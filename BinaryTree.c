#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int value;
  struct Node *left;
  struct Node *right;
};

struct Node *insert(struct Node *root, int target)
{
  struct Node *newNode = malloc(sizeof(struct Node));

  if(root == NULL)
  {
    newNode->value = target;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  if (target < root->value) {
    root->left = insert(root->left, target);
  } else {
    root->right = insert(root->right, target);
  }

  return root;

}

int contains(struct Node *root, int target)
{
  //? Search and return 1 if it includes the given target
  if(root == NULL)
  {
    return 0;
  }
  if(root->value == target)
  {
    return 1;
  }
  else if(target < root->value)
  {
    return contains(root->left, target);
  }
  else if(target > root->value)
  {
    return contains(root->right, target);
  }
  return 0;
}

void print_inorder(struct Node *root)
{
  //? go to the leftest left and then 
  if(root == NULL)
  {
    return;
  }

  print_inorder(root->left);
  printf("%d ", root->value);
  print_inorder(root->right);
}

int main()
{
  struct Node *BinaryTree = NULL;

  BinaryTree = insert(BinaryTree, 15);
  BinaryTree = insert(BinaryTree, 27);
  BinaryTree = insert(BinaryTree, 1);
  BinaryTree = insert(BinaryTree, 5);
  BinaryTree = insert(BinaryTree, 128);

  /* int prob = contains(BinaryTree, 15);
  printf("%d", prob); */

  print_inorder(BinaryTree);

  return 0;
}