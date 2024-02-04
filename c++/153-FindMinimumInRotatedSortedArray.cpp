/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

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
            if(nums[l] <= nums[m]) l = m+1;
            else r = m;
        }        
        return nums[l];
    }
};

class Solution3 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size()-1;
        // if(nums[l] < nums[r]) return nums[l]; // no rotation; this works too
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            int m = l + (r-l)/2;
            if(nums[m] <= nums[r]) r = m;
            else l = m+1;
        }        
        return nums[l];
    }
};

// Time:  O(logn)
// Space: O(1)

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        const int n = nums.size();

        int low = 0;
        int high = nums.size()-1;
        //if(nums[low] <= nums[high]) return nums[low]; this also works comment inside the while loop
    
        while(1){
            int mid = low + (high-low)/2;
            auto next = (mid+1) % n;
            auto prev = (mid+n-1) % n;
            if(nums[low] <= nums[high]) return nums[low];
            else if ((nums[mid] <= nums[next]) && (nums[mid] <= nums[prev])) return nums[mid];
            else if(nums[mid] <= nums[high]) high = mid-1;
            else low = mid+1;
        }
    }
};

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left+1];
    }
};
