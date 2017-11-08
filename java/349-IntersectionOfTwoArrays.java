/*

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

// http://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
// http://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

// use hashtable
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums2.length < nums1.length) return intersection(nums2, nums1);
        Set<Integer> s = new HashSet<>();
        for(int n1:nums1) s.add(n1);
        
        List<Integer> res = new ArrayList<>();

        for (int e: nums2){
            if (s.contains(e)){ 
                res.add(e); 
                s.remove(Integer.valueOf(e)); // very important, else duplicate copies
            }
        }
        int[] f = new int[res.size()];
        int j = 0;
        for(Integer r: res) f[j++] = r;
        return f;        
    }
}
