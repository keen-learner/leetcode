/*

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        // NOTE: gives error without sorting
        sort(candidates.begin(), candidates.end()); 
        dfs(0, candidates, target, cur, res);
        return res;
    }
    
    void dfs(int i, vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        for (; i < candidates.size() && target - candidates[i] >= 0; ++i ) {
            cur.push_back(candidates[i]);
            dfs(i, candidates, target - candidates[i], cur, res);
            cur.pop_back();
        }
    }
};
