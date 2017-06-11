/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

// Iterative
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int previous_size = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const int size = res.size();
            for (int j = 0; j < size; ++j) {
                // Only union non-duplicate element or new union set.
                if (i == 0 || nums[i] != nums[i - 1] || j >= previous_size) {
                    res.emplace_back(res[j]);
                    res.back().emplace_back(nums[i]);
                }
            }
            previous_size = size;
        }
        return res;
    }
};

// following doesn't work
class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        for (long i = 0; i < pow(2, nums.size()); i++ ) {
            for(int j = 0; j < nums.size(); j++) {
                if((i & ((long)1<<j)) && ((j == 0) || temp[temp.size()-1] != nums[j])) 
                    temp.push_back(nums[j]);
            } 
            res.push_back(temp);
            temp.clear();
        }
        return res;        
    }
};

