/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

NOTE: here C can have duplicates, but have to use each element once

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> res;
        sort(c.begin(), c.end());
        vector<int> cur;
        dfs(c, target, 0, cur, res);
        return res;
    }

private:    
    void dfs(vector<int>& c, int target, int st, vector<int>& cur,vector<vector<int>>& res) {
        if(target == 0){
            res.push_back(cur); 
            return;
        }
        if (target < 0) return;
        
        for(int i = st; i < c.size(); i++) {
            if(i > st && c[i] == c[i-1]) continue;
            cur.push_back(c[i]);
            dfs(c,target-c[i],i+1,cur,res);
            cur.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> res;
        sort(c.begin(), c.end());
        vector<int> cur;
        dfs(c, target, 0, cur, res);
        return res;
    }
    void dfs(vector<int>& c, int target, int st, vector<int>& cur,vector<vector<int>>& res){
        if(target == 0){res.push_back(cur); return;}
        
        for(int i=st; i<c.size(); i++){
            if(i>st && c[i]==c[i-1]) continue;
            if(target>=c[i]) {
                cur.push_back(c[i]);
                dfs(c,target-c[i],i+1,cur,res);
                cur.pop_back();
            }
            else return;
        }
    }
};

class Solution2 {
public:
    void dfs(vector<int> &num, int target, vector<vector<int> > &res, vector<int> &r,int st){
        if (target<0){
            return;
        }
        if (target==0){
            res.push_back(r);
            return;
        }
        int pre = -1;
        for (int i=st; i<num.size(); i++){
            if (num[i]!=pre){
                r.push_back(num[i]);
                dfs(num,target-num[i],res,r,i+1);
                pre = num[i];
                r.pop_back();
            }
        }
    }
     
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size()==0){return res;}
        sort(num.begin(),num.end());
        vector<int> r;
        dfs(num,target,res,r,0);
        return res;
    }
};
class Solution3{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        backTracking(candidates.begin(),current,res,candidates,target);
        return res;
    }

    void backTracking(vector<int>::iterator n, vector<int>& current,vector<vector<int>>& res, const vector<int>& candidates, int target){
        if(!target) {res.push_back(current); return;}
        // else if(target>0){
        //     for(;n!=candidates.end()&&*n<=target;++n){
        // else if(target>=*n){
            for(; n!=candidates.end() && target>=*n; ++n){                
                current.push_back(*n);
                backTracking(n+1,current,res,candidates,target-*n);
                current.pop_back();
                while(n+1!=candidates.end()&&*(n+1)==*n) ++n;
            }
        // }
    }
};
