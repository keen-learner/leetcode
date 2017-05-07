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
