/*

Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104

*/

class Solution {
    public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
        if(arr.size() < k) return arr;
        int index = binarySearch(arr, x); // index = 1st elem >= x
        int i = index-1;
        int j = index;

        while(k != 0) {
            if(j>=arr.size() || i>=0 && Math.abs(arr.get(i)-x) <= Math.abs(arr.get(j)-x)) i--;
            else ++j;
            --k;
        }
        ++i;
        return arr.subList(i, j);
    }
    
    int binarySearch(List<Integer> arr, int x) {
        int l = 0;
        int r = arr.size();
        while(l < r) {
            int m = l + (r-l)/2;
            if(arr.get(m) < x) l = m+1;
            else r = m;
        }
        return l;
    }        
    
}
