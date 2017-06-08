/*

Given an array of integers and an integer k, find out whether there are two distinct 
indices i and j in the array such that nums[i] = nums[j] and the absolute difference 
between i and j is at most k.

*/


// http://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup; // has number & last index of number
        for(int i = 0; i < nums.size(); ++i) {
            if(lookup.find(nums[i]) != lookup.end() && (i - lookup[nums[i]] <= k)) return true;
            lookup[nums[i]] = i;
            /*
            if(lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]] = i;
            }
            else {
                if(i - lookup[nums[i]] <= k) return true;
                lookup[nums[i]] = i;
            }
            */
        }
        return false;
    }
};
