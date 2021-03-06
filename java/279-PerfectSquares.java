/*

Given a positive integer n, find the least number of perfect square 
numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9.

*/

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[1+n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j*j<=i; j++) {
                dp[i] = Math.min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];        
    }
}
