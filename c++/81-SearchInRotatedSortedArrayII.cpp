/*
ORiGINAL :
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array 
return its index, otherwise return -1.

You may assume no duplicate exists in the array.

THIS QUESTION:
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //cout<<"left: "<<left<<" right: "<<right<<" mid: "<<mid<<endl;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid]) { //to handle duplicate
                ++left;
            }	 
            else if (nums[left] < nums[mid]) { //left half in sorted order
                /*
                This condition doesn't work, we need to ensure target is in the range 
                by comparing with both extremes.
                Good cases:
                  [3,1] key = 1; [1,3,5] key = 1 
                if(target < nums[mid] && nums[left] <= target) right = mid-1;
                */
                // Note: target < nums[mid] coz we've checked for == already
                if(target < nums[mid] && nums[left] <= target) right = mid-1;
                else left = mid + 1;
            } 
            else { // right half in sorted order
                /*
                Similarly, this won't work. 
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                */
                // Note: target > nums[mid] coz we've checked for == already
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] == nums[left]) {
                ++left;
            } else if ((nums[mid] > nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};



class Solution2 {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] == nums[left]) {
                ++left;
            } else if ((nums[left] <= nums[mid] && nums[left] <= target && target < nums[mid]) ||
                       (nums[left] > nums[mid] && !(nums[mid] < target && target <= nums[right - 1]))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
