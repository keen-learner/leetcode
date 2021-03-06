/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between 
a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str 
contains lowercase letters separated by a single space.

*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        int i = 0;
        string s;
        unordered_map<string, int> m1;
        unordered_map<char, int> m2;
        while(getline(ss, s, ' ')) { // defualt delimiter is \n
            // cout<<i<<"\t"<<s<<"\n";
            if(i == pattern.size() || m1[s] != m2[pattern[i]]) return false;
            m1[s] = i+1;
            m2[pattern[i]] = i+1;
            i++;
        }
        return i==pattern.size();   
    }
};
