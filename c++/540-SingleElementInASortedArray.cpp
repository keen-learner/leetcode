/*

Given a sorted array consisting of only integers where every element 
appears twice except for one element which appears once. Find this 
single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.

*/

ass Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while(l<r) {
            int m = l + (r-l)/2;
            if (nums[m] == nums[m ^ 1])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};

class Solution1 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            // cout<<"l: "<<l<<" r: "<<r<<" m: "<<m<<endl;
            if((m ==0 || nums[m-1]!= nums[m]) 
               && (m == nums.size()-1 || nums[m]!= nums[m+1])) return nums[m];
            if(m % 2 == 0) {
                if(nums[m] == nums[m+1]) l = m+1;
                else r = m-1;
            }
            else {
                if(nums[m] == nums[m-1]) l = m+1;
                else r = m-1;
            }
        }
    }
};
