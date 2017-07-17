/*

Given an array nums, write a function to move all 0's to the end 
of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your 
function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/


/*
// This solution shifts zeroes to the front
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int j = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) {++i;swap(nums[i], nums[j]);}
            ++j;
        }
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int j = 0;
        while(j < nums.size()) {
            if(nums[j]) {++i;swap(nums[i], nums[j]);}
            ++j;
        }
    }
};
