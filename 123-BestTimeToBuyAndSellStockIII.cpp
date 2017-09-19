/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must 
sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k =2;
        if (prices.size() == 0) return 0;
        if (k > prices.size()/2) {
            int res = 0;
            for(int i = 1; i<prices.size(); i++) res += max(0, prices[i]-prices[i-1]);
            return res;
        }
        
        //hold[i,j] - max profit from [0,i] prices with atmost k txns and currently holding a stock
        vector<vector<int>> hold(prices.size(), vector<int>(k+1, 0)); 
        //rel[i,j] - max profit from [0,i] prices with atmost k txns and currently not holding a stock
        vector<vector<int>> rel(prices.size(), vector<int>(k+1, 0));
        
        // hold[0][0] = -prices[0];
        for(int j=0;j<=k;j++) hold[0][j] = -prices[0];
        for(int i=1;i<prices.size();i++) hold[i][0] = max(hold[i-1][0],-prices[i]);
        
        for(int i = 1; i<prices.size(); i++) {
            for(int j = 1; j <= k; j++) {
                hold[i][j] = max(hold[i-1][j], rel[i-1][j] - prices[i]);
                rel[i][j] = max(rel[i-1][j], hold[i-1][j-1] + prices[i]);
            }
        }
        
        return rel[prices.size()-1][k];
        
    }        
    
};
