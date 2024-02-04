/*

Given a sorted array, remove the duplicates in place such that each 
element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in 
place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of 
nums being 1 and 2 respectively. It doesn't matter what you leave 
beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0; // base case necessary
        //int prev = nums[0];
        int j = 0; // keeps track of unique portion; last index of unique portion
        for (int i = 1; i < nums.size(); ++i ){
            if (nums[i] != nums[j]) {
                //prev = nums[i];
                nums[++j] = nums[i];
                //swap(nums[++j], nums[i]); /* this works too */
            }
        }
        return j+1;
    }
};

class Solution0 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0; // base case necessary
        //int prev = nums[0];
        int j = 0; // keeps track of unique portion; last index of unique portion
        for (int i = 1; i < nums.size(); ){
            if(nums[i] == nums[j]) ++i;
            else {
                //prev = nums[i];
                nums[++j] = nums[i];
                //swap(nums[++j], nums[i]);
                ++i;
            }
        }
        return j+1;
    }
};

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int prev = nums[0];
        int j = 0; // keeps track of unique portion; last index of unique portion
        for (int i = 1; i < nums.size(); ){
            if(nums[i] == prev) ++i;
            else {
                prev = nums[i];
                nums[++j] = nums[i];
                //swap(nums[++j], nums[i]);
                ++i;
            }
        }
        return j+1;
    }
};
