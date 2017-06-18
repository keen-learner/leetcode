/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

// Time - O(mn), Space - O(1)

class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
        int rowSize = matrix.size(), colSize = matrix[0].size();
        bool firstRow = false, firstCol = false;

        for(int j = 0; j < colSize; ++j) if(matrix[0][j] == 0) firstRow = true;
        for(int i = 0; i < rowSize; ++i) if(matrix[i][0] == 0) firstCol = true;

        for(int i = 1; i < rowSize; ++i)
            for(int j = 1; j < colSize; ++j)
                if(matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;

        for(int i = 1; i < rowSize; ++i)
            for(int j = 1; j < colSize; ++j)
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;

        if(firstRow) for(int j = 0; j < colSize; ++j) matrix[0][j] = 0;
        if(firstCol) for(int i = 0; i < rowSize; ++i) matrix[i][0] = 0;
    }
};


// Time - O(mn), Space - O(m+n)

class Solution1 {

public:

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false); // NOTE: need initialisation
        vector<bool> col(n, false); // NOTE: need initialisation

        for(int i = 0; i<m; i++){

            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0) {row[i] = true; col[j] = true;}
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++) {
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
