/*

Given a 2D board containing 'X' and 'O' (the letter O), 
capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        for(int i = 0; i<m; i++) { 
            if(board[i][0]== 'O') check(i, 0, board);
            if(board[i][n-1]== 'O') check(i, n-1, board);
        }
        
        for(int j = 0; j<n; j++) { 
            if(board[0][j]== 'O') check(0, j, board);
            if(board[m-1][j]== 'O') check(m-1, j, board);
        }
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
private:
    void check(int i, int j, vector<vector<char>>& board) {
        if(i<0 || i>=board.size() || j<0 
           || j>=board[0].size() || board[i][j]== 'X' || board[i][j]== '1') return;
        board[i][j] = '1';
        check(i+1, j, board);
        check(i, j+1, board);
        check(i-1, j, board);
        check(i, j-1, board);
    }
};
