/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

public class Solution {
    public void rotate(int[][] m) {
        int n = m.length;
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-1-i; j++) {
                int t = m[i][j];
                m[i][j] = m[n-1-j][i];
                m[n-1-j][i] = m[n-1-i][n-1-j];
                m[n-1-i][n-1-j] = m[j][n-1-i];
                m[j][n-1-i] = t;
            }
        }
    }
}
