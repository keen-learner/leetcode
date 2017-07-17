/*

Given an array with n objects colored red, white or blue, sort them 
so that objects of the same color are adjacent, with the colors 
in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color 
red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1;
        int k = nums.size();
        int j = 0;
        while(j < k) {
            if(nums[j] == 0) {
                ++i;
                swap(nums[i], nums[j]);
                ++j;
            }
            else if (nums[j] == 2) {
                --k;
                swap(nums[k], nums[j]);
            }
            else ++j;
        }
    }
};
