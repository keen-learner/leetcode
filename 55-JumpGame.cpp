/*

Given an array of non-negative integers, you are initially 
positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/


// https://discuss.leetcode.com/category/63/jump-game
// https://discuss.leetcode.com/topic/50375/simple-c-solution-with-explanation
// https://discuss.leetcode.com/topic/3443/simplest-o-n-solution-with-constant-space

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        const int n = nums.size();
        // for (int i = 0; i < n && i <= reachable && reachable < n; i++ ) { WORKS TOO
        for (int i = 0;  i <= reachable && reachable < n; i++ ) {
            reachable = max(reachable, i+nums[i]);
        } 
        return reachable >= n-1;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        const int n = nums.size();
        for (int i = 0; i < n && reachable < n; ) {
            reachable = max(reachable, i+nums[i]);
            if (i < reachable) i++;
            else break;
        } 
        return reachable >= n-1;
    }
};

// iterating from back solution : runs n times
class Solution3 {
public:
    bool canJump(vector<int>& A) {
        int n = A.size();
        int last = n-1;
        for(int i = n-2; i >= 0; i--) {
            if(i+A[i] >= last) last=i;
        }
        return last <= 0;
    }
};

// iterating from back solution : breaks early
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLocation = 0;
        for(int i=0; i<nums.size(); i++) {
            if(maxLocation<i) return false; // if previous maxLocation smaller than i, meaning we cannot reach location i, thus return false.
            maxLocation = (i+nums[i]) > maxLocation ? i+nums[i] : maxLocation; // greedy:
        }
        return true;
    }
};
