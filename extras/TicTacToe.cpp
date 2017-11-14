/*

x |  | x 
---------
  | o| ~ 
---------
  |  | x

*/
  
player: 1=x,-1=o,0=empty  
const int N = 3;  
bool DoWin(int r , int c , int player , vector<vector<int>>& board) {
    if(i<0 || i>=N || j<0 || j>=N) ; // raise exception
    board[r][c]  = player;
    
    // check ith row
    int k = 0;
    for(k = 0 ; k<N; k++) {
        if(board[r][k] != player) break;
    }
    if(sum==N) return true; 
    
    // check jth column
    k = 0;
    for(; k<N; k++) {
        if(board[k][c] != player) break;
    }
    if(k==N) return true;
    
    // check diagonal
    for(k=0; k<N; k++ ) {
        if(board[k][k] != player) break;
    }
    if(k==N) return true;
    
    for(k=0;k<N; k++) {
        if(board[k][n-1-k] != player) break;
    }
    if(k==N) return true;
    return false;

}

/*

This is O(n) time and O(n^2) space
Better approach: 
Store players as 1 and -1.
Store column and row sums: 2 vectors of size N. 
And two variables for the two diagonal sums. 
If sum == N or -N ; we know we have a winner. 

*/
