// http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
// http://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/
// http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
// http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/


/*

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next 
pointers respectively in converted DLL. The order of nodes in DLL must be 
same as Inorder of the given Binary Tree. The first node of Inorder traversal 
(left most node in BT) must be head node of the DLL.

*/

// Solution 3
#include <iostream>
using namespace std;

/* A binary tree node has data, and left and right pointers */
struct node
{
  int data;
  node* left;
  node* right;
};

// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BinaryTree2DoubleLinkedList(node *root, node **head)
{
  // Base case
  if (root == NULL) return;

  // Initialize previously visited node as NULL. This is
  // static so that the same value is accessible in all recursive
  // calls
  static node* prev = NULL;

  // Recursively convert left subtree
  BinaryTree2DoubleLinkedList(root->left, head);

  // Now convert this node
  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;

  // Finally convert right subtree
  BinaryTree2DoubleLinkedList(root->right, head);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
  node* new_node = new node;
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
  while (node!=NULL)
  {
    cout << node->data << " ";
    node = node->right;
  }
}

/* Driver program to test above functions*/
int main()
{
  // Let us create the tree shown in above diagram
  node *root   = newNode(10);
  root->left   = newNode(12);
  root->right  = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  // Convert to DLL
  node *head = NULL;
  BinaryTree2DoubleLinkedList(root, &head);

  // Print the converted list
  printList(head);

  return 0;
}


#if 0

// Solution4

// C++ program to convert a given Binary
// Tree to Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure for tree and linked list
struct Node
{
  int data;
  Node *left, *right;
};

// A simple recursive function to convert a given
// Binary tree to Doubly Linked List
// root  --> Root of Binary Tree
// head_ref --> Pointer to head node of created
//       doubly linked list
void BToDLL(Node* root, Node** head_ref)
{
  // Base cases
  if (root == NULL)
    return;

  // Recursively convert right subtree
  BToDLL(root->right, head_ref);

  // insert root into DLL
  root->right = *head_ref;

  // Change left pointer of previous head
  if (*head_ref != NULL)
    (*head_ref)->left = root;

  // Change head of Doubly linked list
  *head_ref = root;

  // Recursively convert left subtree
  BToDLL(root->left, head_ref);
}

// Utility function for allocating node for Binary
// Tree.
Node* newNode(int data)
{
  Node* node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

// Utility function for printing double linked list.
void printList(Node* head)
{
  printf("Extracted Double Linked list is:\n");
  while (head)
  {
    printf("%d ", head->data);
    head = head->right;
  }
}

// Driver program to test above function
int main()
{
  /* Constructing below tree
      5
      / \
      3  6
    / \  \
    1 4  8
    / \  / \
    0 2  7 9 */
  Node* root = newNode(5);
  root->left = newNode(3);
  root->right = newNode(6);
  root->left->left = newNode(1);
  root->left->right = newNode(4);
  root->right->right = newNode(8);
  root->left->left->left = newNode(0);
  root->left->left->right = newNode(2);
  root->right->right->left = newNode(7);
  root->right->right->right = newNode(9);

  Node* head = NULL;
  BToDLL(root, &head);

  printList(head);

  return 0;
}
#endif

#if 0
// Solution 2

// A simple inorder traversal based program to convert a Binary Tree to DLL
#include<stdio.h>
#include<stdlib.h>

// A tree node
struct node
{
  int data;
  struct node *left, *right;
};

// A utility function to create a new tree node
struct node *newNode(int data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return(node);
}

// Standard Inorder traversal of tree
void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
  }
}

// Changes left pointers to work as previous pointers in converted DLL
// The function simply does inorder traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(struct node *root)
{
  static struct node *pre = NULL;

  if (root != NULL)
  {
    fixPrevPtr(root->left);
    root->left = pre;
    pre = root;
    fixPrevPtr(root->right);
  }
}

// Changes right pointers to work as next pointers in converted DLL
struct node *fixNextPtr(struct node *root)
{
  struct node *prev = NULL;

  // Find the right most node in BT or last node in DLL
  while (root && root->right != NULL)
    root = root->right;

  // Start from the rightmost node, traverse back using left pointers.
  // While traversing, change right pointer of nodes.
  while (root && root->left != NULL)
  {
    prev = root;
    root = root->left;
    root->right = prev;
  }

  // The leftmost node is head of linked list, return it
  return (root);
}

// The main function that converts BST to DLL and returns head of DLL
struct node *BTToDLL(struct node *root)
{
  // Set the previous pointer
  fixPrevPtr(root);

  // Set the next pointer and return head of DLL
  return fixNextPtr(root);
}

// Traverses the DLL from left tor right
void printList(struct node *root)
{
  while (root != NULL)
  {
    printf("\t%d", root->data);
    root = root->right;
  }
}

// Driver program to test above functions
int main(void)
{
  // Let us create the tree shown in above diagram
  struct node *root = newNode(10);
  root->left   = newNode(12);
  root->right  = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  printf("\n\t\tInorder Tree Traversal\n\n");
  inorder(root);

  struct node *head = BTToDLL(root);

  printf("\n\n\t\tDLL Traversal\n\n");
  printList(head);
  return 0;
}

#endif

#if 0
// Solution 1

// A C++ program for in-place conversion of Binary Tree to DLL
#include <stdio.h>

/* A binary tree node has data, and left and right pointers */
struct node
{
  int data;
  node* left;
  node* right;
};

/* This is the core function to convert Tree to list. This function follows
steps 1 and 2 of the above algorithm */
node* bintree2listUtil(node* root)
{
  // Base case
  if (root == NULL)
    return root;

  // Convert the left subtree and link to root
  if (root->left != NULL)
  {
    // Convert the left subtree
    node* left = bintree2listUtil(root->left);

    // Find inorder predecessor. After this loop, left
    // will point to the inorder predecessor
    for (; left->right!=NULL; left=left->right);

    // Make root as next of the predecessor
    left->right = root;

    // Make predecssor as previous of root
    root->left = left;
  }

  // Convert the right subtree and link to root
  if (root->right!=NULL)
  {
    // Convert the right subtree
    node* right = bintree2listUtil(root->right);

    // Find inorder successor. After this loop, right
    // will point to the inorder successor
    for (; right->left!=NULL; right = right->left);

    // Make root as previous of successor
    right->left = root;

    // Make successor as next of root
    root->right = right;
  }

  return root;
}

// The main function that first calls bintree2listUtil(), then follows step 3 
// of the above algorithm
node* bintree2list(node *root)
{
  // Base case
  if (root == NULL)
    return root;

  // Convert to DLL using bintree2listUtil()
  root = bintree2listUtil(root);

  // bintree2listUtil() returns root node of the converted
  // DLL. We need pointer to the leftmost node which is
  // head of the constructed DLL, so move to the leftmost node
  while (root->left != NULL)
    root = root->left;

  return (root);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
  node* new_node = new node;
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
  while (node!=NULL)
  {
    printf("%d ", node->data);
    node = node->right;
  }
}

/* Driver program to test above functions*/
int main()
{
  // Let us create the tree shown in above diagram
  node *root   = newNode(10);
  root->left   = newNode(12);
  root->right  = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  // Convert to DLL
  node *head = bintree2list(root);

  // Print the converted list
  printList(head);

  return 0;
}

#endif
