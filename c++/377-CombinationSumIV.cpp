/*

Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
  we can infinite length
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
  we can limit sequence length

*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        vector<int> t(target+1, 0);
        t[0]=1;
        for(int i = 1;i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                if(i >= nums[j]) t[i] += t[i-nums[j]];
            }
        }
        return t[target];
    }
};

