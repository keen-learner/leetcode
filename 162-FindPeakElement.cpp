/*

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

*/

class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) &&
               (mid + 1 == nums.size() || nums[mid] > nums[mid + 1])) {
                return mid;
            } 
            else if (!(mid == 0 || nums[mid - 1] < nums[mid])) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
    
        while(1){
        
            int mid = low + (high-low)/2;
            if ((mid == 0 || nums[mid-1] <= nums[mid]) && (mid == nums.size()-1 || nums[mid+1] <= nums[mid])) return mid;
            else if(mid>0 && nums[mid] < nums[mid-1]) high = mid-1;
            else low = mid+1;
            
            // following are wrong , consider [1, 2]
            //else if(mid>0 && nums[mid] >= nums[mid-1]) low = mid;
            //else high = mid -1;
        }
    }
};
