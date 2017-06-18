/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


// http://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/

// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/


// Time:  O(n^2)
// Space: O(1)

class Solution {

public:

    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<vector<int>> res;
        const int target = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicate.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j  > i+1  && nums[j] == nums[j - 1]) {  // Skip duplicate.
                        ++j;
                    } 
                    else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicate.
                        --k;
                    } 
                    else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {  // Should decrease sum.
                            --k;
                        } 
                        else if (sum < target) {  // Should increase sum.
                            ++j;
                        } 
                        else {
                            res.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }
        return res;
    }
};




class Solution {

public:

    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<vector<int>> res;
        const int target = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate.
            for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                if (j  > i+1  && nums[j] == nums[j - 1]) {  // Skip duplicate.
                    ++j;
                } 
                else if (k < nums.size()-1 && nums[k] == nums[k + 1]) {  // Skip duplicate.
                        --k;
                } 
                else {
                    const auto sum = nums[i] + nums[j] + nums[k];
                    if (sum > target) {  // Should decrease sum.
                        --k;
                    } 
                    else if (sum < target) {  // Should increase sum.
                        ++j;
                    } 
                    else {
                        res.push_back({nums[i], nums[j], nums[k]});
                        ++j, --k;
                    }
                }
            }
        }
        return res;
    }
};


// Brute Force/ Naive O(n^3) solution

class Solution2 {

public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i=0; i < nums.size(); ++i) {
            if(i > 0 && (nums[i] == nums[i-1])) continue;
            for (int j = i+1; j < nums.size(); ++j) {
                if(j > i+1 && (nums[j] == nums[j-1])) continue;
                for(int k = j+1; k < nums.size(); k++) {
                    if (k > j+1 && (nums[k] == nums[k-1])) continue;
                    if(nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return res;
    }
};


