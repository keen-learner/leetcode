/*

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 
1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. 
(If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, 
because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

*/

// Time : O(mn), Space: O(1) modifying orig grid
// m - # rows, n - # columns
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for(int i = 0; i < grid.length; i++) {
            // test case : [[1,1]]
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1) res = Math.max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
    private int dfs(int[][] grid, int i, int j) {
        if(i < 0 || i >= grid.length || j < 0 || 
           j >= grid[i].length || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        return 1+dfs(grid, i+1, j)+dfs(grid, i-1, j)+dfs(grid, i, j+1)+dfs(grid, i, j-1); 
    }
}
