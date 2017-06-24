/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums 
being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

// Time - O(n)
// Space - O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        const int k = 2; // At most k duplicated.

        int j = 0; //last index of atmost 2 duplicate part
        int i = 1;

        for (int i =1; i < nums.size(); ++i) {
            if (nums[j] != nums[i] ||
                (j - k + 1 < 0 || nums[j] != nums[j - k + 1])) {
                /* 3 cases for copying element
                    1. nums[j] != nums[i]
                    2. nums[j] == nums[i] && j < k-1 NOTE: we can have atmost k duplicates, so can have atleast 1 more
                    3. nums[j] == nums[i] && nums[j] != nums[j-k+1], j-k+1 is k steps before j NOTE: we can have atmost k duplicates, so can have atleast 1 more
                
                */    
                nums[++j] = nums[i];
            }
        }

        return j + 1; 
    }
};


