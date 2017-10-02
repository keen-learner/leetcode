/*

You are given an integer array nums and you have to return a new 
counts array. The counts array has the property where counts[i] 
is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

*/

class Solution {
    private int[] count;
    private int[] indices;
    public List<Integer> countSmaller(int[] nums) {
        count = new int[nums.length];
        indices = new int[nums.length];
        for(int i = 0; i< nums.length; i++) indices[i] = i;
        mergeSort(nums, 0, nums.length-1);
        List<Integer> res = new ArrayList<>();
        for(int n: count) res.add(n);
        return res;
    }
    private void mergeSort(int[] nums, int l, int r) {
        if(l>=r) return;
        int m = l + (r-l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
    private void merge(int[] nums, int l, int m, int r) {
        int[] newi = new int[r-l+1];
        int i = l;
        int j = m+1;
        int k = 0;
        int rcount = 0; //count of numbers that go from right half to left
        while(i<=m && j<=r) {
            if(nums[indices[j]] < nums[indices[i]]) {
                newi[k] = indices[j];
                rcount++;
                k++;
                j++;
            }
            else {
                newi[k] = indices[i];
                count[indices[i]] += rcount;
                k++;
                i++;
            }
        }
        while(i<=m) {
            newi[k] = indices[i];
            count[indices[i]] += rcount;
            k++;
            i++;
        }
        while(j<=r) {
            newi[k] = indices[j];
            k++;
            j++;
        }
        for(int z = l; z<=r; z++) {
            indices[z] = newi[z-l];
        }
    }
}

