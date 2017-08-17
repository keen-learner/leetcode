/*

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

*/

class Solution {
    
    private class Node{
        public int val;
        public int pos;
    }
    
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(nums.length < 2) return false;
        Node[] vals = new Node[nums.length];
        for(int i = 0; i < nums.length; i++) {
            Node temp = new Node();
            temp.val = nums[i];
            temp.pos = i;
            vals[i] = temp;
        }
        Arrays.sort(vals, new Comparator<Node>(){
           public int compare (Node a, Node b) {
               if(a.val < b.val) return -1;
               else if(a.val > b.val) return 1;
               return 0;
           } 
        });
        for(int i = 0; i < nums.length-1; i++) {
            for(int j = i+1; j < nums.length; ) {
                if(Math.abs((long)vals[i].val - vals[j].val) <= t && Math.abs(vals[i].pos - vals[j].pos) <= k) return true;
                if(Math.abs((long)vals[i].val - vals[j].val) > t) break;
                else ++j;
            }
        }
        return false;
    }
}
