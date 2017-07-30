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

// https://leetcode.com/articles/coin-change/
// http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
// https://discuss.leetcode.com/category/402/coin-change
// https://www.youtube.com/watch?v=NJuKJ8sasGk
// https://www.youtube.com/watch?v=_fgjrs570YE
// http://stackoverflow.com/questions/6025076/how-to-tell-if-greedy-algorithm-suffices-for-finding-minimum-coin-change
// http://stackoverflow.com/questions/17227330/coin-change-analysis
// http://stackoverflow.com/questions/1986828/coin-changing-algorithm/1986865#1986865
// http://cs.stackexchange.com/questions/6552/when-can-a-greedy-algorithm-solve-the-coin-change-problem
// http://stackoverflow.com/questions/13557979/why-does-the-greedy-coin-change-algorithm-not-work-for-some-coin-sets?rq=1

// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(k)

// DP solution.
/* The lines commented are needed if we want the denominations 
   of coins that are part of our solution.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amounts(amount + 1, numeric_limits<int>::max());
        // vector<int> C(amount + 1, numeric_limits<int>::max());
        amounts[0] = 0;
        // C[0] = 0;
        for(const auto& coin : coins) {
            for(int i = coin; i <= amount; ++i) {
                // int t = amounts[i];
                amounts[i] = min(amounts[i], 
                    amounts[i-coin]==numeric_limits<int>::max()?numeric_limits<int>::max():1 + amounts[i-coin]);
                // if(t != amounts[i]) C[i] = coin;    
            }
        }
        // for(int i = amount; i > 0;) {
        //     cout<<C[i]<<" ";
        //     i -= C[i];
        // }
        // cout<<endl;
        return amounts[amount] != numeric_limits<int>::max() ? amounts[amount] : -1;
    }
};

class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amounts(amount + 1, numeric_limits<int>::max());
        amounts[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            if (amounts[i] != numeric_limits<int>::max()) {
                for (const auto& coin : coins) {
                    if (i + coin <= amount) {
                        amounts[i + coin] = min(amounts[i + coin], amounts[i] + 1);
                    }
                }
            }
        }
        return amounts[amount] == numeric_limits<int>::max() ? -1 : amounts[amount];
    }
};

