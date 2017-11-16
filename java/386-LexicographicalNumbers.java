/*

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.

*/

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int curr = 1;
        for(int i = 0; i<n; i++) {
            res.add(curr);
            if(curr*10<=n) curr *= 10;
            else {
                if(curr >= n) curr /= 10;
                curr++;
                while(curr %10 == 0) curr /= 10;
            }
        }
        return res;
    }

}

// DFS 
class Solution1 {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for(int i = 1; i<10; i++) {
            dfs(res, i, n);
        }
        return res;
    }

    private void dfs(List<Integer> res, int curr, int n) {
        if(curr > n) return;
        res.add(curr);
        if(curr*10 >n) return;
        for(int i = 0; i<10; i++) {
            dfs(res, curr*10+i, n);
        }
    }    
}

