/*

Given a n x n matrix where each of the rows and columns are sorted in ascending 
order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

*/

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int le = matrix[0][0], ri = matrix[n - 1][n - 1];
    int mid = 0;
    while (le < ri) {
      mid = le + (ri-le)/2;
      int num = 0;
      for (int i = 0; i < n; i++) {
        int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        num += pos;
      }
      if (num < k) {
        le = mid + 1;
      }
      else {
        ri = mid;
      }
    }
    return le;
  }
};

// priority queue
class Solution2 {
public:
    struct compare {
        bool operator()(const pair<int,pair<int, int> >& a, 
                const pair<int,pair<int, int> >& b) {
            return a.first>b.first;
        }
    };
    
    int kthSmallest(vector<vector<int>>& arr, int k) {
        
        int m=arr.size(),n=arr[0].size();
        
        priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;
        
        for(int i=0;i<m;i++)
        p.push(make_pair(arr[i][0],make_pair(i,0)));
        
        int x=k;
        int ans;
        while(x--) {
            int e=p.top().first;
            int i=p.top().second.first;
            int j=p.top().second.second;
            ans=e;
            p.pop();
            if(j!=n-1)
            p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
        }
        return ans;
        
    }
};



class Solution3 {
public:
    class comp{
    public:
        bool operator()(tuple<int, int, int>&a, tuple<int, int, int> &b){
            return get<0>(a) > get<0>(b);
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> minHeap; //val, row, col
        for(int i = 0;i<matrix[0].size();i++){
            minHeap.push(make_tuple(matrix[0][i], 0, i));
        }
        tuple<int, int, int> result;
        for(int i = 0;i<k;i++){
            result = minHeap.top();
            minHeap.pop();
            if(get<1>(result) == matrix.size()-1)
                continue;
            int nextRow = get<1>(result) + 1;
            int nextCol = get<2>(result);
            minHeap.push(make_tuple(matrix[nextRow][nextCol], nextRow, nextCol));
        }
        
        return get<0>(result);
    }
};
