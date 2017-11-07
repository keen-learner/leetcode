/*

Given an array of integers and an integer k, find out whether there are two distinct 
indices i and j in the array such that nums[i] = nums[j] and the absolute difference 
between i and j is at most k.

*/


class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i<nums.length; i++) {
            if(!m.containsKey(nums[i])) {
                m.put(nums[i], i);
            }
            else {
                if(i - m.get(nums[i]) <= k ) return true;
                m.put(nums[i], i);
            }
        }
        /*
            NOTE: since we need atmost k, we need to keep only last index
        */
        return false;
        
    }
}
