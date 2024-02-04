/*

You are given a map in form of a two-dimensional integer grid where 1 
represents land and 0 represents water. Grid cells are connected 
horizontally/vertically (not diagonally). The grid is completely surrounded 
by water, and there is exactly one island (i.e., one or more connected land 
cells). The island doesn't have "lakes" (water inside that isn't connected 
to the water around the island). One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the 
perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0;
        int neigh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ++islands;
                    // see bottom
                    if(i<grid.size()-1 && grid[i+1][j]==1) ++neigh;
                    // see right    
                    if(j<grid[i].size()-1 && grid[i][j+1]==1) ++neigh;
                }
            }
        }
        return 4*islands - 2*neigh;
    }
};

class Solution1 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        // int neigh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    res += 4;
                    // see top
                    if(i>0 && grid[i-1][j]==1) res -= 2;
                    // see left    
                    if(j>0 && grid[i][j-1]==1) res -= 2;
                }
            }
        }
        return res;
    }
};

