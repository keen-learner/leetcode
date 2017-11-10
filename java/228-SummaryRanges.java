/*

Given a sorted integer array without duplicates, 
return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]

*/

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if(nums.length==0) return res;
        int n = nums.length;
        int b = nums[0], e = nums[0];
        
        for(int i = 1; i<n; i++) {
            if(nums[i] == e+1) {
                e = nums[i];
            }
            else {
                if(b == e) res.add(String.valueOf(b));
                else res.add(String.valueOf(b) + "->" + String.valueOf(e));
                b = nums[i];
                e = b;
            }
        }
        if(b == e) res.add(String.valueOf(b));
        else res.add(String.valueOf(b) + "->" + String.valueOf(e));
        return res;        
    }
}
