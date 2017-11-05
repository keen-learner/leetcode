/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

class Solution {
    public int findKthLargest(int[] nums, int k) {
        k = nums.length - k; // n-k+1 smallest element
        int l = 0, r = nums.length-1;
        while(true) {
            int piv  = partition(nums, l, r);
            if(piv == k) break;
            if(piv < k) l = piv + 1;
            else r = piv - 1;
        }
        return nums[k];
    }
    private int partition(int[] nums, int l, int r){
        int key = nums[l];
        int i = l;
        for(int j = i+1; j<=r; ++j) {
            if(nums[j] <= key) {
                swap(nums, ++i, j);
            }
        }
        swap(nums, i, l);
        return i;
    }
    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        
    }
}

class Solution1 {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxpq = new PriorityQueue<Integer>(nums.length, new Comparator<Integer>(){
            public int compare(Integer a, Integer b) {
                if(a.compareTo(b) == 1) return -1;
                else if (a.compareTo(b) == -1) return 1;
                return 0;
            }
        });
        
        for(int n:nums) maxpq.offer(n);
        for(int i = 0; i<k-1; i++) maxpq.poll();
        return maxpq.peek();
    }
}
