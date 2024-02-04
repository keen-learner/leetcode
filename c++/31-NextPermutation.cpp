/*

Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the 
lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return ;
        
        int i = n-2;
        while(i > -1 && nums[i] >= nums[i+1]) --i;
        if (i == -1) { reverse(nums.begin(), nums.end()); return;}
        
        // int j = n-1;
        // while(j > i && nums[j] <= nums[i]) --j;
        int j = i+1;
        while(j < n && nums[j] > nums[i]) ++j;
        --j;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
        
    }
};

class Solution2 {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
};
