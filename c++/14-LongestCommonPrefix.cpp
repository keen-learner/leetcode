/*

Write a function to find the longest common prefix string amongst 
an array of strings.

*/

// Time:  O(n * k), k is the length of the common prefix
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            string temp = "";
            for (int j = 0, k = 0; j < res.size() && k < strs[i].size(); ++j, ++k) {
                if (res[j] != strs[i][k]) break;
                temp.push_back(res[j]);
            }
            res = temp;
        }
        return res;
    }
};

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].length(); ++i) {
            for (const auto& str : strs) {
                if (i >= str.length() || str[i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
