/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

// BRUTE FORCE : O(n^2)
// Time Limit Exceeded

class Solution1 {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <=1) return 0;
        unordered_map<int, int> m{{0, -1}};
        int sum = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum = nums[i]==0?-1:1;
            for(int j = i+1; j<nums.size(); j++) {
                sum += nums[j]==0?-1:1;
                if(sum == 0) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() <=1) return 0;
        unordered_map<int, int> m{{0, -1}};
        int sum = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i]==0?-1:1;
            /* CASES
            [0,0,1,0,0,0,1,1]
            [0,1,0,0,1,1,0]
            */
            /* LOGIC:
            If same sum occurs at i then submatrix[m[sum], i-1] has equal no of 1's and 0's 
            */
            if(m.count(sum)) {
                res = max(res, i-m[sum]);
            }
            else m[sum] = i;
        }
        return res;
    }
};
