/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(nums, 0, res);
        return res;
    }
private:
    void helper(vector<int> nums, int st, vector<vector<int>>& res) {
        const auto n = nums.size();
        if(st == n) res.push_back(nums);
        else {
            for(int i = st; i < n; i++) {
                swap(nums[st], nums[i]);
                helper(nums, st+1, res);
            }
        }
    }
};

// Works for with & without duplicates; uses next permutation
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), i, j;
        vector<vector<int>> vv;
        while(true) {
            vv.push_back(nums);
            int i = size-2, j = size-1;
            while(i>0 && nums[i]>=nums[i+1]) i--;
            while(j>0 && nums[i]>=nums[j]) j--;
            if(j == 0) break;
            swap(nums[i], nums[j]);
            j = size-1, i++;
            while(i<j)  swap(nums[i++], nums[j--]);     
        }
        return vv;
    }
};

class Solution2 {
public:
     
    void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==n-1){
            res.push_back(num);
        }
        else{
            for (int i=k;i<n;i++){
                swap(num[k], num[i]);
                perm(num,k+1,n,res);
                //swap(num[k], num[i]); // need this when num is passed by reference. We can pass num by value, then don't need this
            }
        }
    }
 
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        perm(num,0,(num.size()),res);
        return res;
    }
};

class Solution3 {
public:
     
    void perm(vector<int>& num,int k,int n, vector<vector<int> > &res){
        if (k==n-1){
            res.push_back(num);
        }
        else{
            for (int i=k;i<n;i++){
                swap(num[k], num[i]);
                perm(num,k+1,n,res);
                swap(num[k], num[i]); // need this when num is passed by reference. We can pass num by value, then don't need this
            }
        }
    }
 
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        perm(num,0,(num.size()),res);
        return res;
    }
};
