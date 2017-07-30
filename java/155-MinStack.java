/*

Design a stack that supports push, pop, top, and 
retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

public class MinStack {
    private Stack<Integer> s1;
    private Stack<Integer> s2;
    
    /** initialize your data structure here. */
    public MinStack() {
        s1 = new Stack<Integer>();
        s2 = new Stack<Integer>();
    }
    
    public void push(int x) {
        if(x <= s2.peek()) s2.push(x);
        s1.push(x);
    }
    
    public void pop() {
        
    }
    
    public int top() {
        if(!s1.isEmpty()) s1
    }
    
    public int getMin() {
        if(!s2.isEmpty()) return s2.peek(); 
    }
}

class MinStack1 {
    private Stack<Long> s;
    private long m;
    
    /** initialize your data structure here. */
    public MinStack1() {
        s = new Stack<Long>();
    }
    
    public void push(int x) {
        
        if(s.isEmpty()){
            m = x;
            s.push(0L);
            return;
        }
        s.push(x-m);
        if(x<m) m = x;
    }
    
    public void pop() {
        if(s.isEmpty()) return;
        long t = s.pop();
        if (t < 0) m = m-t;
    }
    
    public int top() {
        long t = s.peek();
        if(t>0) return (int)(t+m);
        else return (int)m;
    }
    
    public int getMin() {
        return (int)m; 
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
