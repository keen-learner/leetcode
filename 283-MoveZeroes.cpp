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
