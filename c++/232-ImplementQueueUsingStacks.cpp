/*

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/

// Time:  O(1), amortized
// Space: O(n)

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        A_.emplace(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        B_.pop();
    }

    // Get the front element.
    int peek(void) {
        if (B_.empty()) {
          // Transfers the elements in A_ to B_.
          while (!A_.empty()) {
            B_.emplace(A_.top());
            A_.pop();
          }
        }
        if (B_.empty()) {  // B_ is still empty!
          throw length_error("empty queue");
        }
        return B_.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return A_.empty() && B_.empty();
    }

 private:
  stack<int> A_, B_;
};
