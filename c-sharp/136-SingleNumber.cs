/*

Given an array of integers, every element appears twice except 
for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

*/

public class Solution {
    public int SingleNumber(int[] nums) {
        int res = 0;
        foreach(int n in nums) {
            res ^= n;
        }
        return res;
    }
}
