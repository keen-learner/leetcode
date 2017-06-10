/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
    
private:
    void helper(vector<int> nums, int st, vector<vector<int>>& res) {
        const auto n = nums.size();
        if(st == n) res.push_back(nums);
        else {
            for(int i = st; i < n; i++) {
                if( i > st && nums[i] == nums[st]) continue;
                swap(nums[st], nums[i]);
                helper(nums, st+1, res);
            }
        }
    }
};


// NOTE: Difference between following two methods, num passesd by value & reference respectively
class Solution1 {
public:
    void helper(vector<int> num, int i, int n, vector<vector<int> > &res) {
        if (i == n-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < n; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            helper(num, i+1, n, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        helper(num, 0, num.size(), res);
        return res;
    }
};
class Solution2 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n = num.size();
        vector<vector<int>> res;  
        sort(num.begin(), num.end());    //sort the list
        permuteUnique(num, res, n, 0);
        return res;
    }
    void permuteUnique(vector<int> &num, vector<vector<int>> &res, int n, int s) {
        if (s == n-1) {
            res.push_back(num); 
            return;
        }
        for (int j = s; j < n; j++) {
            if (j > s && num[j] == num[j-1]) continue;    //prevent duplicates
            //set the s-th element in the permutation to be 
            //num[j], while leaving the rest elements sorted
            move(num, j, s);
            permuteUnique(num, res, n, s+1);
            //reset
            move(num, s, j);    
        }
    }
    void move(vector<int> &num, int j, int i) { 
        num.insert(num.begin() + i + (i > j), num[j]);
        num.erase(num.begin() + j + (j > i));
    }
};

// Works for with & without duplicates; uses next permutation
class Solution3 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
