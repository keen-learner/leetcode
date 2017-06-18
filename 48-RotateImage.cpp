/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/


// 90 degree clockwise rotation



class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n/2; i++) { // represents the layer
            for (int j = i; j < n-1-i; j++) { // represents offset 
                int temp = a[i][j];
                a[i][j] = a[n-1-j][i];
                a[n-1-j][i] = a[n-1-i][n-1-j];
                a[n-1-i][n-1-j] = a[j][n-1-i];
                a[j][n-1-i] = temp;
            }   
        } 
    }
};


// 90 degree anticlockwise rotation
// http://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/

class Solution1 {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n/2; i++) { // represents the layer
            for (int j = i; j < n-1-i; j++) { // represents offset 
                int temp = a[i][j];
                a[i][j] = a[j][n-1-i];
                a[j][n-1-i] = a[n-1-i][n-1-j];
                a[n-1-i][n-1-j] = a[n-1-j][i];
                a[n-1-j][i] = temp;
            }   
        } 
    }
};



// 180 degree rotation
// https://stackoverflow.com/questions/36392712/how-do-i-rotate-m-x-n-matrix-180-degrees-in-place

class Solution2 {
public:
    void rotate(std::vector<std::vector<int>>& v) {
      size_t m = v.size();
      size_t n = v[0].size();

      for (size_t i = 0; i < m / 2; ++i) {
          for (size_t j = 0; j < n; ++j) {
              std::swap(v[i][j], v[m - i - 1][n - j - 1]);
          }
      }

      if (m & 1) // if m odd , reverse m'th row
      for (size_t i = 0; i< n/2; ++i) {
          std::swap(v[m/2][i], v[m/2][n-i-1]);
      }
    }
};


