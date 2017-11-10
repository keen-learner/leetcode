/*

Given a sorted integer array without duplicates, 
return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = nums.size();
        int b = nums[0], e = nums[0];
        vector<string> res;
        for(int i = 1; i<n; i++) {
            if(nums[i] == e+1) {
                e = nums[i];
            }
            else {
                if(b == e) res.push_back(to_string(b));
                else res.push_back(to_string(b) + "->" + to_string(e));
                b = nums[i];
                e = b;
            }
        }
        if(b == e) res.push_back(to_string(b));
        else res.push_back(to_string(b) + "->" + to_string(e));
        return res;
    }
};
