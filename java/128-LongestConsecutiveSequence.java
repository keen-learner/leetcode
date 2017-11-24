/*

Given an unsorted array of integers, find the length of the 
longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        Set<Integer> s = new HashSet<>();
        for(int n:nums) s.add(n);
        int res = 1;

        for(int i = 0; i<nums.length; i++ ) {
            if(!s.contains(nums[i]-1)) { // new streak
                int curr = 1;
                int num = nums[i]+1;
                while(s.contains(num)) {
                    ++curr;
                    ++num;
                }
                res = Math.max(res, curr);
            }
        }
        return res;
    }
}

class Solution1 {
    public int longestConsecutive(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        Arrays.sort(nums);
        int res = 1;
        int curr = 1;
        for(int i = 1; i<nums.length; i++ ) {
            if(nums[i] == nums[i-1]) continue;
            else if(nums[i] == nums[i-1]+1) ++curr;
            else {
                res = Math.max(res, curr);
                curr = 1;
            }
        }
        return Math.max(res, curr);
    }
}
