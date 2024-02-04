/*

Given an array of integers and an integer k, you need to find the total number of 
continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr = 0;
        map<int, int> m; //sum, count
        int res = 0;
        m[0]++;
        for(int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            // order for next 2 matters , reverse and error for [1], 0 case
            res += m[curr-k];
            ++m[curr];
        }
        return res;
    }
};

class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            curr = 0;
            for(int j = i; j<nums.size(); j++) {
                curr += nums[j];
                if(curr == k) ++res;
            }
        }
        return res;
    }
};
