/*

Given a 2D binary matrix filled with 0's and 1's, find the 
largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> height(matrix[0].size());
        for(int j = 0; j < matrix[0].size(); j++) height[j] = matrix[0][j]-'0';
        int res = findLargestRectangleInHistogram(height);
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '0') {
                    height[j] = 0;
                }
                else {
                    height[j] += 1;
                }
            }
            res = max(res, findLargestRectangleInHistogram(height));
        }
        return res;
    }

private:
    int findLargestRectangleInHistogram(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        for(int i = 0; i <= heights.size(); ) {
            if(s.empty() || (i<heights.size() && heights[i] > heights[s.top()])) {
                s.push(i);
                i++;
            } 
            else {
                int h = heights[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();;
                res = max(res, h * (i -1 - l));
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '1') maxArea = max(maxArea, BFS(matrix, i, j));
        return maxArea;
    }
    
    int BFS(vector<vector<char>>& matrix, int r, int c){
        int row = r - 1, maxArea = 0;
        while(row >= 0 && matrix[row][c] == '1') row--;
        for(int i = c; i >= 0 && matrix[r][i] == '1'; i--){
            for(int j = row + 1; j <= r; j++)
                if(matrix[j][i] == '0') row = max(row, j);
            maxArea = max(maxArea, (r - row) * (c - i + 1));
        }
        return maxArea;
    }
};
