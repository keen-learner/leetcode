/*

Given an integer array, you need to find one continuous subarray that if 
you only sort this subarray in ascending order, then the whole array 
will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make 
the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/

// // Time: O(n),
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Let [i,j] be the range
        int i = 0, j = -1; // needed for [1,2,3,4] case
        // i is the last index from end for which min[i, n-1] != nums[i]
        // j is the last index from start for which max[0, j] != nums[j]
        int lmin = INT_MAX;
        for(int k = nums.size()-1; k >=0 ; k--) {
            lmin = min(lmin, nums[k]);
            if(lmin != nums[k]) i = k; 
        }
        
        int lmax = nums[i]; // needed for [2,1] case
        for(int k = i+1; k<nums.size(); k++) {
            lmax = max(lmax, nums[k]);
            if(lmax != nums[k]) j = k;
        }
        
        return j - i + 1;
    }
};


// Time: O(n), two pass
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r && nums[l]<=nums[l+1]) ++l; // l-last sorted index from start
        if(l==r) return 0;
        while(r>l && nums[r]>=nums[r-1]) --r; // r- last sorted index from end 
        int lmax = INT_MIN; // local max
        int lmin = INT_MAX; // local min
        for(int i = l; i<=r; i++) { //NOTE: loop range includes l and r coz nums[l]<=lmin and nums[r] >= lmax
            lmax = max(nums[i], lmax);
            lmin = min(nums[i], lmin);
        }
        while(l>=0 && lmin < nums[l]) --l;
        while(r < nums.size() && nums[r] < lmax) ++r;
        // [l+1, r-1] is the range
        return r-1 - (l+1) +1;
    }
};

// sort solution
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t(nums);
        sort(t.begin(), t.end());
        int i=0,j=nums.size()-1;
        while(i<nums.size() && nums[i]==t[i]) i++;
        // while(j>=0 && nums[j]==t[j]) j--; //[1,2,3,4] case
        while(j>i && nums[j]==t[j]) j--;
        return j-i+1;
    }
};
