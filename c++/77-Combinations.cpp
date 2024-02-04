/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n < 1 || k < 1) return res;
        if(k > n) k = n;
        
        int start = (1<<k)-1, end = 1<<n;//the binary of 'start' has exactly k 1s and each 1 means a element in the result.
        while(start < end) {
            int t = 1,p = 1;
            vector<int> cur;
            while(t < end) { // we check every bit position
                if(start & t) {
                    cur.push_back(p);//because the result is combine of [1-n],we push p.
                    /* if(cur.size() == k) break; //This not needed*/
                }
        p++;
                t = t << 1;//check the next bit
            }
            res.push_back(cur);
            //get the next combination
            // let start be xxx01110
            int x = start & (-start); //get rightmost set bit, x = 00000010, NOTE: -x = ~x +1 coz of 2's complement
            int y = start + x; // y = xxx10000
            start = ((start & (~y))/x >> 1) | y;
            // start = ((start ^ y)/x >> 2) | y; slower than above statement
        }
        return res;
    }
};

class Solution0 {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res; 
        if ((k<1)||(n<1)||(k>n)){return res;}
        // vector <int> cand;
        // for (int i = 1; i<=n;i++){
        //     cand.push_back(i);
        // }
        vector<int> cur;
        dfs(n,0,k,cur, res);
        return res;
    }

private:
    void dfs(int &n, int st, int k, vector<int>& cur, vector<vector<int>>& res){
        if (cur.size()==k){
            res.push_back(cur);
            return;
        }
        for (int i = st; i < n; i++){
            cur.push_back(i+1);
            dfs(n,i+1,k,cur,res);
            cur.pop_back();
        }
    }
};

class Solution1 {
public:
    void dfs(vector<int> &cand, int st, int ed, vector<int> &lr, vector<vector<int> >& res){
        if (lr.size()==ed){
            res.push_back(lr);
            return;
        }
        for (int i = st; i< cand.size();i++){
                lr.push_back(cand[i]);
                dfs(cand,i+1,ed,lr,res);
                lr.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res; 
        if ((k<1)||(n<1)||(k>n)){return res;}
        vector <int> cand;
        for (int i = 1; i<=n;i++){
            cand.push_back(i);
        }
        vector<int> lr;
        dfs(cand,0,k,lr, res);
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int> > res;
    void dfs(vector<int> &cand, int st, int ed, vector<int> &lr){
        if (lr.size()==ed){
            res.push_back(lr);
            return;
        }
        for (int i = st; i< cand.size();i++){
                lr.push_back(cand[i]);
                dfs(cand,i+1,ed,lr);
                lr.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        res.clear();
         
        if ((k<1)||(n<1)||(k>n)){return res;}
        vector <int> cand;
        for (int i = 1; i<=n;i++){
            cand.push_back(i);
        }
        vector<int> lr;
        dfs(cand,0,k,lr);
        return res;
    }
};

