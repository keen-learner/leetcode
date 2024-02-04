/*

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

// Iterative 

/*
This problem can also be solved iteratively. Take [1, 2, 3] in the problem 
statement as an example. The process of generating all the subsets is like:

Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> res(1);
        /*
        // we need to sort if there was another requirement: "Elements in a subset must be in non-descending order"  
        sort(nums.begin(), nums.end()); 
        */
        for (int i = 0; i < nums.size(); ++i) {
            const int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.emplace_back(res[j]);
                res.back().emplace_back(nums[i]);
            }
        }
        return res;
    }
};

// Recursion 1 (pass curr by reference)
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;  
        genSubsets(nums, 0, curr, res);
        return res; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            genSubsets(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
};

// Recursion 2 (pass curr by value)
// NOTE: DOESN'T WORK
class Solution22 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;  
        genSubsets(nums, 0, curr, res);
        return res; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int> curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            genSubsets(nums, i + 1, curr, res);
            //curr.pop_back();
        }
    }
};

// Bit Manipulation
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        for (long i = 0; i < pow(2, nums.size()); i++ ) {
            for(int j = 0; j < nums.size(); j++) {
                if(i & ((long)1<<j)) temp.push_back(nums[j]);
            } 
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};

// Bit Manipulation 2 (Using Bitset)
class Solution4 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < pow(2, nums.size()); i++){
            std::bitset<32> bits(i);
            vector<int> rowVector;
            for(int j = 0; j < 32; j++) {
                if(bits.test(j))
                    rowVector.push_back(nums[j]);
            }
            ans.push_back(rowVector);
        }
        return ans;
    }
};
