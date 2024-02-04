/*

Given an unsorted array of integers, find the length of the 
longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

// Time and Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;

        for(int i = 0; i<n; i++) {
            if(s.find(nums[i]-1) == s.end()) { // we have new sequence
                int num = nums[i]+1;
                int curr = 1;
                while(s.find(num)!= s.end()) {
                    ++num;
                    ++curr;
                }
                res = max(curr, res);
            }
        }
        return res;
    }
};

// Time: O(nlogn)
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        sort(nums.begin(), nums.end());
        int res = 1;
        int curr = 1;
        for(int i = 1; i<n; i++) {
            // case [1,2,0,1]
            if(nums[i] == nums[i-1]) continue;
            else if(nums[i] == 1 + nums[i-1]) curr++;
            else {
                res = max(res, curr);
                curr = 1;
            }
        }
        return max(res, curr);
    }
};
