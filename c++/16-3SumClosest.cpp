/*

Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int res = numeric_limits<int>::max();
        int min_diff = numeric_limits<int>::max();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // Skip duplicate.
            for(int j = i+1, k = nums.size()-1; j < k;) {
                const auto sum = nums[i] + nums[j] + nums[k];
    
                if (sum > target) {  // Should decrease sum.
                    --k;
                } 
                else if (sum < target) {  // Should increase sum.
                    ++j;
                } 
                else {
                    return target;
                }
    
                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int res = numeric_limits<int>::max();
        int min_diff = numeric_limits<int>::max();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicate.
                for(int j = i+1, k = nums.size()-1; j < k;) {
                    const auto sum = nums[i] + nums[j] + nums[k];
    
                    if (sum > target) {  // Should decrease sum.
                        --k;
                    } 
                    else if (sum < target) {  // Should increase sum.
                        ++j;
                    } 
                    else {
                        return target;
                    }
    
                    if (abs(sum - target) < min_diff) {
                        min_diff = abs(sum - target);
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
