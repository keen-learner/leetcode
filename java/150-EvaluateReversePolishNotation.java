/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<Integer>();
        for(String t:tokens) {
            if(t.equals("+")) {
               int b = s.pop();
               int a = s.pop();
               s.push(a+b); 
            }   
            else if(t.equals("-")) {
               int b = s.pop();
               int a = s.pop();
               s.push(a-b);
            }   
            else if(t.equals("*")) {
               int b = s.pop();
               int a = s.pop();
               s.push(a*b); 
            }   
            else if(t.equals("/")) {
               int b = s.pop();
               int a = s.pop();
               s.push(a/b); 
            }   
            else {
                s.push(Integer.parseInt(t));
            }
        }
        return s.peek();
    }
}
