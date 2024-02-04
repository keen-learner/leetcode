/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } 
            else {
                ++i;
            }
        }        
        for (i = 0; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }
};

class Solution2 {
public:
    int firstMissingPositive(vector<int>& A) {
        const int n = A.size();
         for (int i = 0; i<n;i++){
            if ( (A[i]>0)&&(A[i]<=n)){
                while (A[i]!=(i+1)){ // can use the following too
                // while (i!=A[i]-1){  
                    if ((A[i]>n)||(A[i]<=0)||(A[A[i]-1]==A[i])) break;
                    swap(A[i], A[A[i]-1]);
                }
            }
        }
         
        int i=0;
        for(; i < n && A[i] == i+1; ++i);
        return i+1;
        // for (; i<n;i++){
        //     if (A[i]!=(i+1)){
        //         return i+1;
        //     }
        // }
        // return i+1;       
    }
};

// Following doesn't work; understand why
class Solution3 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && i != nums[i] - 1) {
                /* note this is wrong because infinite loop 
                in the case array is [1,1]
                */
                swap(nums[i], nums[nums[i] - 1]);
            } 
            else {
                ++i;
            }
        }        
        for (i = 0; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }
};

