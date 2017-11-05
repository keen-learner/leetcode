/*

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size()-1;
        // if(nums[l] < nums[r]) return nums[l]; // no rotation; this works too
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            int m = l + (r-l)/2;
            if(nums[l] == nums[m]) ++l;
            else if(nums[l] <= nums[m]) l = m+1;
            else r = m;
        }        
        return nums[l];
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            int m = l + (r-l)/2;
            if(nums[l] == nums[m]) ++l;
            else if(nums[m] <= nums[r]) r = m;
            else l = m+1;
        }        
        return nums[l];        
    }
};

// Time:  O(logn)
// Space: O(1)

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[left]) {
                ++left;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
