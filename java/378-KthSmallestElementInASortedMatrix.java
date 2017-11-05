/*

Given a n x n matrix where each of the rows and columns are sorted in ascending 
order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

*/

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;        
        PriorityQueue<Node> minpq = new PriorityQueue<Node>(m, new Comparator<Node>(){
            public int compare(Node a , Node b){
                return a.val - b.val;
            }
        });
        for(int i = 0; i<m; i++) {
            Node t = new Node();
            t.val = matrix[i][0];
            t.r = i;
            t.id = 0;
            minpq.offer(t);
        }
        for(int i = 0; i<k-1; i++) {
            Node tmp = minpq.poll();
            if(tmp.id < n-1) {
                Node t = new Node();
                t.id = tmp.id + 1;
                t.r = tmp.r;
                t.val = matrix[t.r][t.id];
                minpq.offer(t);
            }
        }
        return minpq.peek().val;
    }
    private class Node{
        int val; // current value from this row
        int r; // row 
        int id; // current element's column from this row 
    }
}

class Solution2 {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int count = getLessEqual(matrix, mid);
            if (count < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
    
    private int getLessEqual(int[][] matrix, int val) {
        int res = 0;
        int n = matrix.length, i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] > val) i--;
            else {
                res += i + 1;
                j++;
            }
        }
        return res;
    }
}
