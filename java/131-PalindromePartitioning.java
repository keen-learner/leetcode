/*

Given a string s, partition s such that every substring of 
the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/


class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<List<String>>();
        if(s == null || s.length() == 0) return res;
        List<String> curr = new ArrayList<>();
        helper(res, s, 0, curr);
        return res;
    }
    

    private void helper(List<List<String>> res, String s, int st, List<String> curr) {
        if(st == s.length()) {
            res.add(new ArrayList(curr));
            return;
        }
        for(int i = st; i<s.length(); i++) {
            if(isPalindrome(s, st, i)){ // [st, i] substring
                curr.add(s.substring(st, i+1));
                helper(res, s, i+1, curr);
                curr.remove((int)curr.size()-1);
            }
        }
    }
    
    private boolean isPalindrome(String s, int i, int j) {
        while(i<=j) {
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}
