/*

Find the length of the longest substring T of a given string (consists 
of lowercase letters only) such that every character in T appears no 
less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

class Solution {
    public int longestSubstring(String s, int k) {
        return helper(s, k, 0, s.length());
    }
    
    private int helper(String s, int k, int start, int end) {
        int[] counts = new int[26];
        for(int t = start; t<end; t++) {
            ++counts[s.charAt(t)-'a'];
        }
        int res = 0;
        for(int i = start; i<end;) {
            // skip i for which count < k
            while(i < end && (counts[s.charAt(i)-'a'] < k)) i++;
            if(i == end) break; // all less than k
            // i is >=k find first j for which count < k
            int j = i;
            while(j < end && (counts[s.charAt(j)-'a'] >= k)) j++;
            if(i == start && j == end) return end - start;
            res = Math.max(res, helper(s, k, i, j));
            i = j;
        }
        return res;
    }
}
