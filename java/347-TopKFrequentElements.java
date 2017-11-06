/*

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>(); // num, count
        for(int num : nums) count.put(num, count.getOrDefault(num,0)+1);
        
        PriorityQueue<Node> maxpq = new PriorityQueue(count.size(), new Comparator<Node>(){
            public int compare(Node a, Node b){
                return b.c - a.c;
            }
        }); 
        
        for(Map.Entry<Integer, Integer> m: count.entrySet()) {
            Node tmp = new Node();
            tmp.val = m.getKey();
            tmp.c = m.getValue();
            maxpq.offer(tmp);
        }
        
        List<Integer> res = new ArrayList<>();
        
        for(int i = 0; i < k; ++i) {
            Node t = maxpq.poll();
            res.add(t.val);
        }
        
        return res;        
    }
    
    private class Node {
        int c; //count
        int val;
    }
}
