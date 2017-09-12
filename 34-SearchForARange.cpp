/*

Given an array of integers sorted in ascending order, find the 
starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

// different meaning of upper bound in this and next solution
// upper bound returns last of N in NNNNYYYYY
// lower bound gives first Y in NNNYYYY always
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(nums.size() == 0) return {-1,-1};
        int st = lowerBound(nums, target);
        int end = upperBound(nums, target);
        // if(st < nums.size() && nums[st] == target)
        if(end < nums.size() && nums[end] == target)
            return {st, end};
        return {-1, -1};
    }
 
private:
    
    int lowerBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    } 
    
    int upperBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) {
                right = mid-1;
            } 
            else {
                left = mid;
            }
        }
        // return left;
        return nums.size()>0 && nums[left]>target?-1:left;
    }
};

// Changed predicate
// upper bound gives first Y in NNNNYYYY
class Solution0 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(nums.size() == 0) return {-1,-1};
        int st = lowerBound(nums, target);
        int end = upperBound(nums, target);
        if(st < nums.size() && nums[st] == target) 
            return {st, end-1};
        return {-1, -1};
    }
 
private:
    
    int lowerBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    } 
    
    int upperBound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};


// Time:  O(logn)
// Space: O(1)
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto start = lower_bound(nums.cbegin(), nums.cend(), target);
        const auto end = upper_bound(nums.cbegin(), nums.cend(), target);
        if (start != nums.cend() && *start == target) {
            return {start - nums.cbegin(), end - nums.cbegin() - 1};
        }
        return {-1, -1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);

        if (begin < nums.size() && nums[begin] == target) {
            return {begin, end - 1};
        }

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
