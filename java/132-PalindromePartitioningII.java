/*

Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

class Solution {
    public int minCut(String c) {
        char[] s = c.toCharArray();
        int n = s.length;

        int[] cut = new int[n+1];
        for(int i = 0; i<=n; i++) cut[i] = i-1;

        for(int i = 0; i<n; i++) {
            for(int j = i, k = i; j>=0 && k<n && s[j]==s[k]; j--,k++) 
                cut[k+1] = Math.min(cut[k+1], 1+cut[j]);

            for(int j = i-1, k = i; j>=0 && k<n && s[j]==s[k]; j--,k++) 
                cut[k+1] = Math.min(cut[k+1], 1+cut[j]);
        }
        return cut[n];
    }    
}

class Solution1 {
    public int minCut(String s) {
        char[] c = s.toCharArray();
        int n = c.length;

        int[] cut = new int[n];
        boolean[][] pal = new boolean[n][n];

        for(int i = 0; i < n; i++) {
            int temp = i;
            for(int j = 0; j <= i; j++) {
                if(c[j] == c[i] && (j + 1 > i - 1 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;  
                    temp = j == 0 ? 0 : Math.min(temp, cut[j - 1] + 1);
                }
            }
            cut[i] = temp;
        }
        return cut[n - 1];
    }    
}
