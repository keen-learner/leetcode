/*
// http://www.geeksforgeeks.org/check-if-two-given-strings-are-at-edit-distance-one/

Given two strings S and T, determine if they are both one edit distance apart.
*/


/*

This is the way that before the Edit Distance expansion, but this question is not 
that difficult problem, this question only let us determine whether the editing 
distance of the two strings is 1, then we only need the following 
three cases To consider on the line:

1. The difference between the length of two strings is greater than 1, 
then return False directly

2. The difference between the length of the two strings is equal to 1, then 
the long string to remove a character, the rest should be the same as the short string

3. The difference between the length of the two strings is equal to 0, 
then the characters of the two strings corresponding to the location can only be one different.

*/


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs(s.size() - t.size()) > 1) return false;
        if (s.size() > t.size()) swap(s, t); // s smaller than t
        int i = 0;
        int j = 0;
        bool flag = false;

        while (i < s.size() && j < t.size()) {
          if(s[i] != t[j]) {
            if(flag) return false; // already 1 edit done
            flag = true;
            if (s.size() == t.size()) ++i;
          } 
          else {
            ++i;
          }
          ++j;
        }
        return true;
    }
};
