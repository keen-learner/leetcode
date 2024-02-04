/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    long n = nums.size();
    long long sum = (n *(n+1))/2;
    for (int i = 0; i < n; i++) {
            sum = sum - nums[i];
    }
    return sum;
  }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
 public:
  int missingNumber(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); ++i) {
      num ^= nums[i] ^ (i + 1);
    }
    return num;
  }
};

// Time:  O(n)
// Space: O(n)
class Solution3 {
 public:
  int missingNumber(vector<int>& nums) {
    vector<int> expected(nums.size()); 
    iota(expected.begin(), expected.end(), 1);  // Costs extra space O(n)
    return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>()) ^
           accumulate(expected.cbegin(), expected.cend(), 0, bit_xor<int>());
  }
};

