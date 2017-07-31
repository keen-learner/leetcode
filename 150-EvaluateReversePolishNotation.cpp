/*
POSTFIX EXPRESSION
NOTE: for PREFIX , we cna go from right to left and evaluate


Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> s {"+","-","*","/"};
        stack<string> res;
        for(int i = 0; i < tokens.size(); i++) {
            auto it = s.find(tokens[i]);
            if(it != s.end()) { //operator found
                string t2 = res.top();
                res.pop();
                string t1 = res.top();
                res.pop();
                if(*it == "+") {
                    res.push(to_string(stoi(t1) + stoi(t2)));
                }
                else if(*it == "-") {
                    res.push(to_string(stoi(t1) - stoi(t2)));
                }
                else if(*it == "*") {
                    res.push(to_string(stoi(t1) * stoi(t2)));
                }
                else if(*it == "/") {
                    res.push(to_string(stoi(t1) / stoi(t2)));
                }
            } 
            else { // number found
                res.push(tokens[i]);
            }
        }
        return stoi(res.top());
    }
};
