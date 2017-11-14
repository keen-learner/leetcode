// A C program to demonstrate linked list based implementation of queue
#include <stdlib.h>
#include <stdio.h>

struct Node {
  int val;
  struct Node* next;
};

struct Node* createNode(int val) {
  struct Node* t = (struct Node*)malloc(sizeof(struct Node));
  t->val = val;
  t->next = NULL;
  return t;
}
void enQueue(struct Node** front, struct Node** rear, int val) {
  struct Node* t = createNode(val);
  if((*rear) == NULL) { //first element
    *rear = *front = t;
    return;
  }
  (*rear)->next = t;
  *rear = t;
}

struct Node* deQueue(struct Node** front, struct Node** rear) {
  if(*front == NULL) printf("\nempty queue");
  struct Node* t = *front;
  *front = (*front)->next;
  if((*front) == NULL) {
    printf("\nqueue has become empty");
    *rear = NULL;
  }
  return t;
}

// Driver Program to test anove functions
int main() {
  struct Node *front = NULL;
  struct Node *rear = NULL;
  struct Node* t = NULL;


  enQueue(&front, &rear, 10);
  enQueue(&front, &rear, 20);
  t = deQueue(&front, &rear); free(t);
  t = deQueue(&front, &rear); free(t);
  enQueue(&front, &rear, 30);
  enQueue(&front, &rear, 40);
  enQueue(&front, &rear, 50);
  struct Node* n = deQueue(&front, &rear); 
  if (n != NULL)
    printf("\nDequeued item is %d", n->val); //30
  free(n);  
  return 0;

}
