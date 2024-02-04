/*

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.

*/

// https://discuss.leetcode.com/topic/55131/ac-200ms-c-solution-beats-98/7
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) cur /= 10;
                cur++;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};

// DFS
class Solution3 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        // for (int i = 1; i < 10; i++) {
        dfs(res, 1, n);
        // }
        return res;
    }
    
    void dfs(vector<int>& res, int curr, int n) {
        if(curr>n) return;
        res.push_back(curr);
        dfs(res, curr*10, n);
        if(curr%10 != 9) dfs(res, curr+1, n);
    } 
};

class Solution2 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            dfs(res, i, n);
        }
        return res;
    }
    
    void dfs(vector<int>& res, int curr, int n) {
        if(curr>n) return;
        res.push_back(curr);
        if(10*curr > n) return;
        for(int i = 0; i<10; i++) {
            dfs(res, curr*10+i, n);    
        }
        
    } 
};

// TLE
class Solution1 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i<=n; i++) res.push_back(i);
        sort(res.begin(), res.end(), [](int a, int b){
            return to_string(a) <  to_string(b);
        });
        return res;
    }
};
