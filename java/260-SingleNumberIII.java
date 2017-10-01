/*

Given an array of numbers nums, in which exactly two elements appear only once and 
all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, 
[5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you 
implement it using only constant space complexity?

*/

class Solution {
    public int[] singleNumber(int[] nums) {
        int axorb = 0;
        for(int n : nums) axorb = axorb ^ n;
        // axorb has set bits in positions where a and b differ
        int diff = axorb & ~(axorb-1); //get rightmost 1
        int[] res = new int[2];
        for(int n : nums) {
            int index = (diff & n) != 0 ? 1:0;
            res[index] ^= n;
        }
        return res;        
    }
}
