/*

You are given coins of different denominations and a total amount of 
money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

*/

public class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1]; //dp[i]: min count of making amount i
        for(int i = 1; i<= amount; i++) dp[i] = -1;
        dp[0] = 0;
        for(int i = 1; i<= amount; i++) {
            for(int c :coins) {
                if (i < c ) continue; 
                if(dp[i-c] != -1) {
                    dp[i] = dp[i] == -1?1+dp[i-c]:Math.min(dp[i], 1+dp[i-c]);
                }
            }
        }
        return dp[amount];
    }
}
