class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                ++i;
                swap(nums[i], nums[j]);
            } 
            ++j;
        }
        return i+1;
    }
};
