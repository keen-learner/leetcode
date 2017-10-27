/*

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

class Solution {
    public void wiggleSort(int[] nums) {
        if(nums.length<2) return;
        int n = nums.length;
        int[] t = Arrays.copyOf(nums, n);
        Arrays.sort(t); //ascending order
        
        int j = n-1; //upper half
        int k = (n-1)/2; //lower half
        for(int i = 0; i < n; i++) {
            nums[i] = i%2==0? t[k--]: t[j--];
        }
    }
}

class Solution1 {
    public void wiggleSort(int[] nums) {
        if(nums.length<2) return;
        int n = nums.length;
        int[] t = Arrays.copyOf(nums, n);
        Arrays.sort(t); //ascending order
        for(int i = 0, j=n-1; i<j; i++, j--) {
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
        int j = 0; //upper half
        int k = n/2; //lower half
        for(int i = 0; i < n; i++) {
            nums[i] = i%2==0? t[k++]: t[j++];
        }
    }
}
