/*

Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination 
should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        if(n<1 || k<1) return res;
        helper(res, cur, 1, k, n);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& cur, int st, int k, int target){
        if (!k && !target) {
            res.push_back(cur);
            return;
        }
        if (target < 0) return;
        for (int i = st; i<10; i++){
            cur.push_back(i);
            helper(res, cur, i+1, k-1, target-i);
            cur.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        if(n<1 || k<1) return res;
        helper(res, cur, 1, k, n);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& cur, int st, int k, int target){
        if(!k && !target) {
            res.push_back(cur);
            return;
        }
        for (int i = st; i<10 && target >= i; i++){
            cur.push_back(i);
            helper(res, cur, i+1, k-1, target-i);
            cur.pop_back();
        }
    }
};
