/*

Given a non-empty array containing only positive integers, find if 
the array can be partitioned into two subsets such that the sum 
of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false; //odd sum means false;
        sum /= 2; //new target for subset
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        // for(int j = 1; j <=sum; j++) dp[0][j] = false;
        // for(int i = 1; i<=nums.size(); i++) dp[i][0] = false;
        
        for(int i = 0; i<nums.size(); i++) { //0..i nums
            for(int j = sum; j > 0; j--) { // NOTE: j going from sum to 1; else error
                // dp[i+1][j] = dp[i][j] || (j>=nums[i]?dp[i][j - nums[i]]:false);
                dp[j] = dp[j] || (j>=nums[i]?dp[j - nums[i]]:false);
            }
            // if(i != nums.size()-1) swap(dp[0], dp[1]);
        }
        return dp[sum];
    }
};


class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false; //odd sum means false;
        sum /= 2; //new target for subset
        vector<vector<bool>> dp(2, vector<bool>(sum+1, false));
        dp[0][0] = true;
        // for(int j = 1; j <=sum; j++) dp[0][j] = false;
        // for(int i = 1; i<=nums.size(); i++) dp[i][0] = false;
        
        for(int i = 0; i<nums.size(); i++) { //0..i nums
            for(int j = 1; j <= sum; j++) {
                // dp[i+1][j] = dp[i][j] || (j>=nums[i]?dp[i][j - nums[i]]:false);
                dp[1][j] = dp[0][j] || (j>=nums[i]?dp[0][j - nums[i]]:false);
            }
            if(i != nums.size()-1) swap(dp[0], dp[1]);
        }
        return dp[1][sum];
    }
};

class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false; //odd sum means false;
        sum /= 2; //new target for subset
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1, false));
        dp[0][0] = true;
        for(int j = 1; j <=sum; j++) dp[0][j] = false;
        for(int i = 1; i<=nums.size(); i++) dp[i][0] = false;
        
        for(int i = 0; i<nums.size(); i++) { //0..i nums
            for(int j = 1; j <= sum; j++) {
                dp[i+1][j] = dp[i][j] || (j>=nums[i]?dp[i][j - nums[i]]:false);
            }
        }
        return dp[nums.size()][sum];
    }
};
