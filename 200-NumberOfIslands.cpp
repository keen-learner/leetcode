/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of 
islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all four edges 
of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1') {
                    // res += dfs(visited, i, j, grid)?1:0;
                    res += dfs(i, j, grid)?1:0;
                }
            }
        }
        return res;
    }
    
private:
    // bool dfs(vector<vector<bool>>& visited, int i, int j, vector<vector<char>>& grid) {
    bool dfs(int i, int j, vector<vector<char>>& grid) {
        // if(i<0 || i>=grid.size()||j<0||j>=grid[i].size() || visited[i][j] || grid[i][j] =='0') return false;
        if(i<0 || i>=grid.size()||j<0||j>=grid[i].size() || grid[i][j] =='0') return false;
        // visited[i][j] = true;
        grid[i][j] = '0'; //setting to 0 so that dfs doesnt start again in foll statements from i,j resulting in infinite loop
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        // grid[i][j] = '1'; //NOTE: Dont reset
        return true;
    }
};

class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1') {
                    res += dfs(visited, i, j, grid)?1:0;
                }
            }
        }
        return res;
    }
    
private:
    bool dfs(vector<vector<bool>>& visited, int i, int j, vector<vector<char>>& grid) {
        if(i<0 || i>=grid.size()||j<0||j>=grid[i].size() || visited[i][j] || grid[i][j] =='0') return false;
        visited[i][j] = true;
        dfs(visited, i+1, j, grid);
        dfs(visited, i-1, j, grid);
        dfs(visited, i, j-1, grid);
        dfs(visited, i, j+1, grid);
        return true;
    }
};
