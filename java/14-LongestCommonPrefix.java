/*

Write a function to find the longest common prefix string amongst 
an array of strings.

*/

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0 ) return "";
        // if(strs.length == 1) return strs[0];
        String res = strs[0];
        int n = strs.length;
        for(int i = 1; i<n; i++){
            int j = 0; //for result
            int k = 0; // for ith string
            while(j<res.length() && k<strs[i].length() && res.charAt(j) == strs[i].charAt(k)) {++j; ++k;}
            res = res.substring(0, j);
        }
        return res;
    }
}
