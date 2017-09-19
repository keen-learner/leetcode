/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as 
many transactions as you like (ie, buy one and sell one share of the 
stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same 
time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

*/

class Solution {
    public int maxProfit(int[] prices) {
      if (prices.length < 2) return 0;
      int res = 0;
        //  max profit when you buy the stock at day i.
      int[] hold = new int[prices.length];
        Arrays.fill(hold, 0);
        // max profit when you sell the stock at day i
      int[] rel = new int[prices.length];
        Arrays.fill(rel, 0);
        hold[0] = -prices[0];

        for (int i = 1; i < prices.length; ++i) {
          rel[i] = Math.max(hold[i - 1] + prices[i], rel[i - 1] - prices[i - 1] + prices[i]);
          if (res < rel[i])  res = rel[i]; //record the max rel[i]
          if (i == 1) hold[i] = hold[0] + prices[0] - prices[1];
          else hold[i] = Math.max(rel[i - 2] - prices[i], hold[i - 1] + prices[i - 1] - prices[i]);
      }
      return res;
        // return rel[prices.size()-1];        
    }
}
