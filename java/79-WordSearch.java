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
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0) return false;
        int m = board.length;
        int n = board[0].length;
        // boolean[][] visited = new boolean[m][n];
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(dfs(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
    private boolean dfs(int i, int j, char[][] board, String word, int st) {
        if(st == word.length()) return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length 
            || board[i][j] != word.charAt(st)) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        if(dfs(i+1, j, board, word, st+1) ||
            dfs(i, j+1, board, word, st+1) ||
            dfs(i-1, j, board, word, st+1) ||
            dfs(i, j-1, board, word, st+1)) return true;
        board[i][j] = temp;
        return false;
    }
}

class Solution1 {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0) return false;
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(dfs(visited, i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
    private boolean dfs(boolean[][] visited, int i, int j, char[][] board, String word, int st) {
        if(st == word.length()) return true;
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length 
           || visited[i][j] || board[i][j] != word.charAt(st)) return false;
        visited[i][j] = true;
        if(dfs(visited, i+1, j, board, word, st+1) ||
            dfs(visited, i, j+1, board, word, st+1) ||
            dfs(visited, i-1, j, board, word, st+1) ||
            dfs(visited, i, j-1, board, word, st+1)) return true;
        visited[i][j] = false;
        return false;
    }
}
