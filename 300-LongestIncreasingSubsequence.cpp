/*

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


*/

// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
//Time: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { //also giving the sequence
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};

// Time: O(n^2)
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i<nums.size(); i++) {
            int tempmax = 0;
            for(int j = i-1; j>=0; j--) {
                if(nums[i] > nums[j])
                    tempmax = max(dp[j], tempmax); 
            }
            dp[i] = 1 + tempmax;
            res = max(res, dp[i]);
        }
        return res;
    }
};
