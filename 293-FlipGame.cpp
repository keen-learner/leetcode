/*

You are playing the following Flip Game with your friend: Given a 
string that contains only these two characters: + and -, you and your 
friend take turns to flip twoconsecutive "++" into "--". The game 
ends when a person can no longer make a move and therefore the other 
person will be the winner.

Write a function to compute all possible states of the string after one valid move.
For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].


*/

// Time:  O(c * n + n) = O(n * (c+1)), n is length of string, c is count of "++"
// Space: O(1), no extra space excluding the result which requires at most O(n^2) space
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {  // O(n) time
            if (s[i] == '+') {
                for ( ; i < n - 1 && s[i + 1] == '+'; ++i) {  // O(c) time
                    s[i] = s[i + 1] = '-';
                    res.push_back(s);  // O(n) to copy a string
                    s[i] = s[i + 1] = '+';
                }
            }
        }
        return res;
    }
};
