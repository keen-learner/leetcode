/*

Given an array of integers and an integer k, you need to find the total number of 
continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution {
    public int subarraySum(int[] nums, int k) {
        int curr = 0;
        Map<Integer, Integer> m = new HashMap<>(); //sum, count
        int res = 0;
        m.put(0,1);
        for(int i = 0; i < nums.length; i++) {
            curr += nums[i];
            // order for next 2 matters , reverse and error for [1], 0 case
            if(m.containsKey(curr-k)) res += m.get(curr-k);
            m.put(curr, 1+m.getOrDefault(curr, 0));
        }
        return res;       
    }
}

class Solution1 {
    public int subarraySum(int[] nums, int k) {
        int curr = 0;
        int res = 0;

        for(int i = 0; i < nums.length; i++) {
            curr = 0;
            for(int j = i; j<nums.length; j++) {
                curr += nums[j];
                if(curr == k) ++res;
            }
        }
        return res;        
    }
}
