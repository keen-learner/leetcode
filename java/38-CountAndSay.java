/*

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

*/


// http://www.geeksforgeeks.org/look-and-say-sequence/
// https://discuss.leetcode.com/topic/2068/how-to-proof-the-count-is-always-less-than-10/3
// Time:  O(n * 2^n)
// Space: O(2^n)

class Solution {
    public String countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";
        String res = "1";
        for(int i = 2; i<=n; i++) {
            StringBuilder sb = new StringBuilder();
            char ch = res.charAt(0);
            int c = 1;
            for(int j = 1; j<res.length(); j++) {
                if(res.charAt(j) == ch) c++; //same char, increase count
                else {
                    sb.append(Integer.toString(c));
                    sb.append(Character.toString(ch));
                    ch = res.charAt(j);
                    c = 1;
                }
            }
            sb.append(Integer.toString(c));
            sb.append(Character.toString(ch));
            res = sb.toString();
        }
        return res;
    }
}
