/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/


// O(n) solution using hashmap 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i<nums.length; i++) {
            if(m.containsKey(target-nums[i])) return new int[]{i, m.get(target-nums[i])};
            m.put(nums[i], i);
        }
        return new int[2];
    }
}
