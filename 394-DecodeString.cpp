/*

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string 
inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white 
spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any 
digits and that digits are only for those repeat numbers, k. For example, 
there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
    
private:
    string helper(string& s, int& i) {
        string res;
        while(i<s.size() && s[i]!=']') {
            if(isdigit(s[i])) {
                int j = i;
                while(j<s.size() && isdigit(s[j])) j++;
                int n = stoi(s.substr(i, j-1 - i + 1));
                i = ++j; // j is '[' 
                string t = helper(s, i);
                i++;
                while(n>0) {
                    res += t;
                    --n;
                }
            }
            else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};

class Solution3 {
public:
    string decodeString(string s) {
        string res;
        stack<string> strs;
        int i = 0;
        while (i < s.size()) {
            if(isdigit(s[i])) {
                int j = i;
                while(i<s.size() && isdigit(s[i])) i++;
                strs.push(s.substr(j, i-1 -j + 1));
            }
            else if (s[i] != ']') {
                string p;
                p.push_back(s[i]);
                strs.push(p);
                i++;
            } 
            else { //pop for ']'
                string t;
                while(strs.top() != "[") {
                    t = strs.top() + t;
                    strs.pop();
                }
                strs.pop(); // pop "["
                int n = stoi(strs.top());
                strs.pop();
                string ss;
                for(int i = 0; i<n; i++) ss += t;
                strs.push(ss);
                i++;
            }
        }
        while(!strs.empty()) {
            res = strs.top() + res;
            strs.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    string decodeString(string s) {
        string res;
        stack<int> nums;
        stack<string> strs;
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int j = i;
                while(j<s.size() && isdigit(s[j])) j++;
                int n = stoi(s.substr(i, j-1 - i + 1));
                nums.push(n);
                i = j; // j is '['
            } 
            else if (s[i] == '[') {
                strs.push(res);
                res.clear();
                i++;
            } 
            else if (s[i] == ']') {
                int n = nums.top();
                nums.pop();
                string t = strs.top();
                strs.pop();
                while(n>0){
                    --n;
                    t += res;
                }
                res = t;
                i++;
            } 
            else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};


// Time:  O(n)
// Space: O(h), h is the depth of the recursion
class Solution1 {
public:
    string decodeString(string s) {
        string curr;
        stack<int> nums;
        stack<string> strs;
        int n = 0;
        for (const auto& c: s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else if (c == '[') {
                nums.emplace(n);
                n = 0;
                strs.emplace(curr);
                curr.clear();
            } else if (c == ']') {
                for (; nums.top() > 0; --nums.top()) {
                    strs.top() += curr;
                }
                nums.pop();
                curr = strs.top();
                strs.pop();
            } else {
                curr += c;
            }
        }
        return strs.empty() ? curr : strs.top();
    }
};
