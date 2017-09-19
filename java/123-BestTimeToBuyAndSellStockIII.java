/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must 
sell the stock before you buy again).

*/

class Solution {
    public int maxProfit(int[] prices) {
        int k =2;
        if (prices.length == 0) return 0;
        if (k > prices.length/2) {
            int res = 0;
            for(int i = 1; i<prices.length; i++) res += Math.max(0, prices[i]-prices[i-1]);
            return res;
        }
        
        //hold[i,j] - max profit from [0,i] prices with atmost k txns and currently holding a stock
        int[][] hold = new int[prices.length][k+1]; 
        //rel[i,j] - max profit from [0,i] prices with atmost k txns and currently not holding a stock
        int[][] rel = new int[prices.length][k+1];
        
        // hold[0][0] = -prices[0];
        for(int j=0;j<=k;j++) hold[0][j] = -prices[0];
        for(int i=1;i<prices.length;i++) hold[i][0] = Math.max(hold[i-1][0],-prices[i]);
        
        for(int i = 1; i<prices.length; i++) {
            for(int j = 1; j <= k; j++) {
                hold[i][j] = Math.max(hold[i-1][j], rel[i-1][j] - prices[i]);
                rel[i][j] = Math.max(rel[i-1][j], hold[i-1][j-1] + prices[i]);
            }
        }
        return rel[prices.length-1][k];          
    }
}
