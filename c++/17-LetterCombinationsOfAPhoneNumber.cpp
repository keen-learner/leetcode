/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        vector<string> keys{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string curr;
        helper(res, curr, keys, digits, 0);
        return res;
    }
    void helper(vector<string>& res, string& curr, vector<string>& keys, string& digits, int i) {
        if(i == digits.size()) {
            res.push_back(curr); 
            return;
        }
        string poss = keys[digits[i]-'0'];
        for(char c: poss) {
            curr.push_back(c);
            helper(res, curr, keys, digits, i+1);
            curr.pop_back();
        }
    }
};
