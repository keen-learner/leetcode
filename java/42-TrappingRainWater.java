/*

Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap 
after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

/*
Idea is to calculate unit of water at evry index.
At i, find tallest bar to left and right.
Water at i is the difference between height[i] and min(left, right)  

*/

/*
[2,3] -> 0
[2,0,3] -> 2
[2,0,2] -> 2
*/

class Solution {
    public int trap(int[] height) {
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = height.length-1;
        int res = 0;
        
        while(l<=r) {
            if(lmax < rmax) {
                res += Math.max(lmax-height[l], 0);
                lmax = Math.max(lmax, height[l]);
                l++;
            }    
            else {
                res += Math.max(rmax-height[r], 0);
                rmax = Math.max(rmax, height[r]);
                r--;
            }
        }
        return res;
    }
}
