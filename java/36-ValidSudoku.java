/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are 
filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.

*/

class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rflag = new boolean[9][9]; // for 9 rows
        boolean[][] cflag = new boolean[9][9]; // for 9 columns
        boolean[][] flag = new boolean[9][9]; // for 9 3X3 sub matrices
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') {
                    int num = (board[i][j] - '0') - 1;
                    if(rflag[i][num] || cflag[j][num] || flag[(i/3)*3 + (j/3)][num]) return false;
                    rflag[i][num] = true;
                    cflag[j][num] = true;
                    flag[(i/3)*3 + (j/3)][num] = true;
                }
            }
        }
                    
        return true;        
    }
}

class Solution1 {
    public boolean isValidSudoku(char[][] board) {
        // 1. check rows
        for(int i = 0; i<9; i++) { // board size: 9 X 9
            if(!helper(board, i, i, 0, 8)) return false;
        }


        // 2. check columns
        for(int i = 0; i<9; i++) { // board size: 9 X 9
            if(!helper(board, 0, 8, i, i)) return false;
        }

        // 3. check 3 X 3 submatrix
        for(int i = 0; i<9; i+=3) {
            for(int j = 0; j<9; j+=3) {
                if(!helper(board, i, i+2, j, j+2)) return false;
            }
        }

        return true; // passes all checks        
    }
    
    private boolean helper(char[][] board, int rs, int re, int cs, int ce) {
        boolean[] flag = new boolean[9];
        for(int i = rs; i<= re; i++) {
            for(int j = cs; j<= ce; j++) {
              if(board[i][j] != '.') {
                  int num = (int)(board[i][j]-'0') - 1;
                  if(flag[num]) return false;
                  flag[num] = true;
              }
            }   
        }
        return true;
    }
}

