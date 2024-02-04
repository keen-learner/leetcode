/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {   
        const int n = nums.size();
        if(n < 1) return 0;

        int l = 0;
        int r = n;
        while(l < r) {
            auto m = l + (r-l)/2;
            
            if(nums[m] < target) {
                l = m+1;
            } 
            else {
                r = m;
            } 
        }
        
        return l;
    }
};

class Solution3 {
public:
    int searchInsert(vector<int>& nums, int target) {   
        const int n = nums.size();
        if(n < 1) {
            return 0;
        }
        
        int low = 0;
        int high = n-1;
        int pos;
        while(low <= high) {
            auto mid = low + (high-low)/2;
            
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                high = mid - 1;
                pos = mid;
            } else {
                low = mid + 1;
                pos = mid + 1;
            }
        }
        
        return pos;
    }
};

class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int m = l+ (r-l)/2;
            if(nums[m] < target) l = m+1;
            else if(nums[m] > target) r = m-1;
            else return m;
        }
        return l;
    }
};

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int m = l+ (r-l)/2;
            if(nums[m] >= target) r = m-1;
            else l = m+1;
        }
        return l;
    }
};
