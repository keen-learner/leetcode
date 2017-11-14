/*

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

*/

class Solution1 {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j = 0;
        int cnt = 1;
        
        if (n<=1) return n;
        
        for (int i = 1; i < n; ++i){
            if (chars[i-1] == chars[i]){
                ++cnt;
            } else {
                write(chars, j, chars[i-1], cnt);
                cnt = 1;
            }
        }
        write(chars, j, chars.back(), cnt);
        chars.resize(j);
        return j;
    }

    void write(vector<char>& chars, int& j, char c, int cnt){
        chars[j++] = c;
        if (cnt == 1) return;
        string s = to_string(cnt);
        for (int i = 0; i < s.size(); ++i){
            chars[j++] = s[i];
        }
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0, j = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (i + 1 == chars.size() || chars[i + 1] != chars[i]) {
                chars[j++] = chars[anchor];
                if (i > anchor) { // for single char dont't need count
                    string s = to_string(i-anchor+1);
                    for(char c: s) chars[j++] = c;
                }
                anchor = i + 1;
            }
        }
        return j;
    }
};
