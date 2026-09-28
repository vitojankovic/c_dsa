#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

int height(struct Node *root)
{

  if(root == NULL)
  {
    return 0;
  }

  else{
    return 1 + MAX(height(root->left), height(root->right));
  }
}

int count_nodes(struct Node *root)
{
  if(root == NULL)
  {
    return 0;
  }

  return 1 + count_nodes(root->left) + count_nodes(root->right);
}

struct Node *find_min(struct Node *root)
{
  // minimum is always the leftmost node in a BST
  // if left is NULL return current
  // else find_min left
  if(root->left == NULL)
  {
    return root;
  }
  else
  {
    return find_min(root->left);
  }
}

struct Node *delete_node(struct Node *root, int target)
{
  // First find the node, if root->value == target then found
  // if target<root->value then delete_node(root->left)
  // if target>root->value then delete_node(root->right)
  // if root == NULL return 0
  if(root == NULL)
  {
    return NULL;
  }

   if (target < root->value) {
    root->left = delete_node(root->left, target);
  }
  else if (target > root->value) {
    root->right = delete_node(root->right, target);
  }
  else {
    // target == root->value -- THIS is the node to delete
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    else if (root->right == NULL) {
      struct Node *temp = root->left;   // save BEFORE freeing
      free(root);
      return temp;
    }
    else if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    }
    else {
      // two children: steal the successor's VALUE, don't steal the node
      struct Node *successor = find_min(root->right);
      root->value = successor->value;                        // copy value up
      root->right = delete_node(root->right, successor->value); // remove the duplicate from below
    }
}
}

int main()
{
  struct Node *BinaryTree = NULL;

  BinaryTree = insert(BinaryTree, 15);
  BinaryTree = insert(BinaryTree, 27);
  BinaryTree = insert(BinaryTree, 1);
  BinaryTree = insert(BinaryTree, 5);
  BinaryTree = insert(BinaryTree, 128);
  BinaryTree = insert(BinaryTree, 129);
  BinaryTree = insert(BinaryTree, 130);

  /* int prob = contains(BinaryTree, 15);-
  printf("%d", prob); */

  print_inorder(BinaryTree);

  /*int temp = height(BinaryTree);
  printf("%d", temp);*/

  /*struct Node *minNode = find_min(BinaryTree);

  printf("%d", minNode->value);*/

  delete_node(BinaryTree, 128);

  printf("\n");

  print_inorder(BinaryTree);

  return 0;
}