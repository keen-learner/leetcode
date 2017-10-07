/*

There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

*/

// DFS
class Solution0 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int groups = 0;
        for(int i = 0; i < M.size(); i++) {
            groups += !visited[i] ? dfs(M, i, visited),1:0;
        }
        return groups;
    }
    void dfs(vector<vector<int>>& M, int& i, vector<bool>& visited) {
        if(visited[i]) return ; //already visited
        visited[i] = true;
        for(int j = 0; j < M.size(); j++) {
            // if(i!=j && M[i][j] && !visited[j]) dfs(M, j, visited); /*works too*/
            if(M[i][j]) dfs(M, j, visited);
        }
        return;
    }  
};

// DFS
class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < visited.size(); i++) {
            groups += dfs(i, M, visited) > 0;
        }
        return groups;
    }

private:
    int dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        if (visited[i]) {
            return 0;
        }

        int ppl = 1;
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && M[i][j]) {
                ppl += dfs(j, M, visited);
            }
        }

        return ppl;
    }
};


// UNION FIND
class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M){
  const int n(M.size());
  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0;j < n; ++j) {
      if (M[i][j] && !uf.is_connected(i,j)) {
        uf.union_set(i,j);
      }
    }
  }
  return uf.get_count();
    }
    
    class UnionFind {
    public:
      UnionFind(int n) :m_num(n),m_ids(n,-1),m_count(n){
        for (int i=0;i<m_num;++i) {
          m_ids[i] = i;
        }
      }
      bool is_connected(int node1, int node2) {return m_ids[node1] == m_ids[node2];}  
      int find(int node) {return m_ids[node];}
      int get_count() {return m_count;}
      // If two nodes are in different disjoint-set, union their set together.
      // Here we go through all the nodes, if any node's id is the same as node2,
      // which means it is at the same disjoint-set with node2, we reset its id value
      // to be the same as node1.
      void union_set(int node1,int node2) {
        const int id1 = m_ids[node1], id2 = m_ids[node2];
        if (id1 != id2) {
          for (int i = 0;i < m_num; ++i) {
            if (m_ids[i] == id2) m_ids[i] = id1;
          }
          -- m_count;
        }
      }
    private:
      int m_num; // how many nodes in total
      int m_count; // how many disjoint-set 
      vector<int> m_ids; // ID of each node,ID is the representative of each disjoint-set
    };  
};
