/*

There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

*/

class Solution {
    public int findCircleNum(int[][] m) {
        if(m == null || m.length == 0) return 0;
        int n = m.length;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        
        int res = 0;
        for(int i = 0; i<n; i++) {
            res += dfs(i, visited, m)?1:0;    
        }
        return res;
    }
    private boolean dfs(int i, boolean[] visited, int[][] m) {
        if(visited[i]) return false;
        visited[i] = true;
        for(int j = 0; j<m.length; j++) {
            // if(m[i][j]==1) dfs(j, visited, m); // WORKS TOO
            if(i != j && m[i][j]==1) dfs(j, visited, m);
        }
        return true;
    }
}

// Union Find
class Solution1 {
    public int findCircleNum(int[][] m) {
        if(m == null || m.length == 0) return 0;
        int n = m.length;
        int[] parents = new int[n];
        int res = n;
        for(int i = 0; i<n; i++) parents[i] = i;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(m[i][j] == 1) {
                    int pi = i;
                    int pj = j;
                    while(parents[pi]!=pi) pi = parents[pi];
                    while(parents[pj]!=pj) pj = parents[pj];
                    if(pi != pj) {
                        parents[pi] = pj;
                        --res;
                    }
                }
            }
        }
        return res;
    }
}
