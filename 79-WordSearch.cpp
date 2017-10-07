/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0) return false;
        int m = board.size();
        int n = board[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                // if(dfs(visited, i, j, board, 0, word)) return true;
                if(dfs(i, j, board, 0, word)) return true;
            }
        }
        return false;
    }
    
private:
    // bool dfs(vector<vector<bool>>& visited, int i, int j, vector<vector<char>>& board, int st, string& word) {
    bool dfs(int i, int j, vector<vector<char>>& board, int st, string& word) {
        if(st == word.size()) return true; // NOTE: order of 2 statements very important
        if(i<0 || i>=board.size()||j<0||j>=board[i].size() || board[i][j] != word[st]) return false;
        
        // bool temp = visited[i][j];
        auto temp = board[i][j];
        // visited[i][j] = true;
        board[i][j] = '#';
        
        if( dfs(i+1, j, board, 1+st, word) ||
            dfs(i-1, j, board, 1+st, word) ||
            dfs(i, j-1, board, 1+st, word) ||
            dfs(i, j+1, board, 1+st, word)) return true;
        
        // visited[i][j] = temp;
        board[i][j] = temp; // Need to reset for dfs starting from other indices
        return false;
    }
};

class Solution1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(dfs(visited, i, j, board, 0, word)) return true;
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<bool>>& visited, int i, int j, vector<vector<char>>& board, int st, string& word) {
        if(st == word.size()) return true; // NOTE: order of 2 statements very important
        if(i<0 || i>=board.size()||j<0||j>=board[i].size() || visited[i][j] || board[i][j] != word[st]) return false;
        
        bool temp = visited[i][j];
        visited[i][j] = true;
        
        if( dfs(visited, i+1, j, board, 1+st, word) ||
            dfs(visited, i-1, j, board, 1+st, word) ||
            dfs(visited, i, j-1, board, 1+st, word) ||
            dfs(visited, i, j+1, board, 1+st, word)) return true;
        
        visited[i][j] = temp;
        return false;
    }
};
