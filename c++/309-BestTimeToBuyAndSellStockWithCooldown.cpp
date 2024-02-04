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

// https://discuss.leetcode.com/topic/34687/an-8ms-c-dp-solution-easy-to-understand
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() < 2) return 0;
      int res = 0;
        //  max profit when you buy the stock at day i.
      vector<int> hold(prices.size(), 0);
        // max profit when you sell the stock at day i
      vector<int> rel(prices.size(), 0);
      hold[0] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
          rel[i] = max(hold[i - 1] + prices[i], rel[i - 1] - prices[i - 1] + prices[i]);
          if (res < rel[i])  res = rel[i]; //record the max rel[i]
          if (i == 1) hold[i] = hold[0] + prices[0] - prices[1];
          else hold[i] = max(rel[i - 2] - prices[i], hold[i - 1] + prices[i - 1] - prices[i]);
      }
      return res;
        // return rel[prices.size()-1];
    }
};

// also see
// https://discuss.leetcode.com/topic/30431/easiest-java-solution-with-explanations/2
