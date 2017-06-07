/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one 
duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

class Solution0 {
  public:
    int findDuplicate(vector<int>& nums) {
      int l = 1;
      int r = nums.size() - 1;
      while (l <= r) {
        if (l == r) return l;

        int m = l + (r - l) / 2;
        int count = 0;
        for (auto n : nums) {
          if (n >=l && n <= m) ++count;
        }
        if (count > m-l+1) r = m;
        else l = m+1;
      }
      return -1; 
    }
};


class Solution1 {
  public:
    int findDuplicate(vector<int>& nums) {
      return helper(nums, 1, nums.size()-1);

    }
    int helper(vector<int>& nums, int l, int r) {
      int m = l + (r-l)/2;
      int count = 0;
      if(l == r) return l;
      for(int i = 0; i<nums.size(); ++i) {
        if(nums[i] >=l && nums[i] <= m) ++count;
      }
      if (count > m-l+1) return helper(nums, l,m);
      return helper(nums, m+1,r);
    }
};

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[slow];
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      fast = 0;
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;    
    }
};

class Solution3 {
  public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }

      fast = 0;
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;    
    }
};
