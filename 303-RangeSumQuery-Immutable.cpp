/*

Given an integer array nums, find the sum of the elements between 
indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/

class NumArray {
public:
    NumArray(vector<int> nums):sums(1+nums.size(), 0) {
        for(int i = 0; i<nums.size(); i++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return (sums[j+1] - sums[i]);
    }
private:
    vector<int> sums; // sums[i] = sum of [0, i-1] elements
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
