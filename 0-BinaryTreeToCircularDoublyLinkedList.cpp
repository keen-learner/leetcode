// http://cslibrary.stanford.edu/109/TreeListRecursion.html
// http://articles.leetcode.com/convert-binary-search-tree-bst-to/
// http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

/*

Here's the formal problem statement: Write a recursive function treeToList
(Node root) that takes an ordered binary tree and rearranges the internal 
pointers to make a circular doubly linked list out of the tree nodes. 
The "previous" pointers should be stored in the "small" field and the 
"next" pointers should be stored in the "large" field. The list should be 
arranged so that the nodes are in increasing order.

*/ 

// C++ Program to convert a Binary Tree
// to a Circular Doubly Linked List
#include<iostream>
using namespace std;

// To represents a node of a Binary Tree
struct Node
{
  struct Node *left, *right;
  int data;
};

// A function that appends rightList at the end
// of leftList.
Node *concatenate(Node *leftList, Node *rightList)
{
  // If either of the list is empty
  // then return the other list
  if (leftList == NULL)
    return rightList;
  if (rightList == NULL)
    return leftList;

  // Store the last Node of left List
  Node *leftLast = leftList->left;

  // Store the last Node of right List
  Node *rightLast = rightList->left;

  // Connect the last node of Left List
  // with the first Node of the right List
  leftLast->right = rightList;
  rightList->left = leftLast;

  // Left of first node points to
  // the last node in the list
  leftList->left = rightLast;

  // Right of last node refers to the first
  // node of the List
  rightLast->right = leftList;

  return leftList;
}

// Function converts a tree to a circular Linked List
// and then returns the head of the Linked List
Node *bTreeToCList(Node *root)
{
  if (root == NULL)
    return NULL;

  // Recursively convert left and right subtrees
  Node *left = bTreeToCList(root->left);
  Node *right = bTreeToCList(root->right);

  // Make a circular linked list of single node
  // (or root). To do so, make the right and
  // left pointers of this node point to itself
  root->left = root->right = root;

  // Step 1 (concatenate the left list with the list 
  //     with single node, i.e., current node)
  // Step 2 (concatenate the returned list with the
  //     right List)
  return concatenate(concatenate(left, root), right);
}

// Display Circular Link List
void displayCList(Node *head)
{
  cout << "Circular Linked List is :\n";
  Node *itr = head;
  do
  {
    cout << itr->data <<" ";
    itr = itr->right;
  } while (head!=itr);
  cout << "\n";
}


// Create a new Node and return its address
Node *newNode(int data)
{
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Driver Program to test above function
int main()
{
  Node *root = newNode(10);
  root->left = newNode(12);
  root->right = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  Node *head = bTreeToCList(root);
  displayCList(head);

  return 0;
}


#if 0

/*

LEETCODE

When I first see this problem, my first thought was in-order traversal. 
Couldn’t we modify the nodes’ left and right pointers as we do an in-order 
traversal of the tree? However, we have to beware not to modify the 
pointers and accessing it at a later time.

As we traverse the tree in-order, we could safely modify a node’s left pointer 
to point to the previously traversed node as we never use it once we reach a node. 
We would also need to modify the previously traversed node’s right pointer to point 
to the current node. Note: The previously traversed node meant here is not its 
parent node. It is the node’s previous smaller element.

Easy approach, right? But wait, we are still missing two more steps. First, we 
did not assign the list’s head pointer. Second, the last element’s right pointer 
does not point to the first element (similar to the first element’s left pointer).

How do we solve this? My approach is pretty easy: Just update the current node’s 
right pointer to point back to the head and the head’s left pointer to point to 
current node in each recursive call. As the recursion ends, the list’s head and 
tail would be automagically updated with the correct pointers. Don’t forget to 
check for this special case: A list with only one element should have its left and 
right pointers both pointing back to itself.


A double-linked list with a length of one.
Do you think this approach works? I bet it did! The run time complexity for 
this solution is O(N) since we are essentially doing a modified in-order 
traversal. It does have some extra assignments in each recursive call though. 
But overall I am quite satisfied with this approach because it is intuitive and 
easy to follow. Besides, we are adapting an existing algorithm (in-order traversal) 
to solve this problem, isn’t this just neat?

*/

// This is a modified in-order traversal adapted to this problem.
// prev (init to NULL) is used to keep track of previously traversed node.
// head pointer is updated with the list's head as recursion ends.
void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
  if (!p) return;
  treeToDoublyList(p->left, prev, head);
  // current node's left points to previous node
  p->left = prev;
  if (prev)
    prev->right = p;  // previous node's right points to current node
  else
    head = p; // current node (smallest element) is head of
              // the list if previous node is not available
  // as soon as the recursion ends, the head's left pointer 
  // points to the last node, and the last node's right pointer
  // points to the head pointer.
  Node *right = p->right;
  head->left = p;
  p->right = head;
  // updates previous node
  prev = p;
  treeToDoublyList(right, prev, head);
}
 
// Given an ordered binary tree, returns a sorted circular
// doubly-linked list. The conversion is done in-place.
Node* treeToDoublyList(Node *root) {
  Node *prev = NULL;
  Node *head = NULL;
  treeToDoublyList(root, prev, head);
  return head;
}

#endif
