/*

Given an array of integers, find if the array contains any duplicates. Your function should 
return true if any value appears at least twice in the array, and it should 
return false if every element is distinct.

*/

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};

// Brute Force Time - O(n^2)
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i == j) continue;
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
