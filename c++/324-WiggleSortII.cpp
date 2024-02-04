/*

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

// https://discuss.leetcode.com/topic/32861/3-lines-python-with-explanation-proof?page=1
// https://discuss.leetcode.com/topic/52116/o-n-o-1-after-median-without-virtual-indexing

// sort and Time: O(n), Space: O(n) 
class Solution1 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        vector<int> temp(nums);
        sort(temp.rbegin(), temp.rend()); //descending order
        int k = 0; //upper half
        int j = n/2; //lower half
        for(int i = 0; i < n; i++) {
            /* On even index put lower half elements
               On odd index put upper elements 
            */
            nums[i] = i%2 == 0 ? temp[j++] : temp[k++];
        }
    }
};

// sort and Time: O(n), Space: O(n)
// nice trick for indices
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.rbegin(), sorted.rend());
        int n = nums.size();
        int m = n | 1; // for even n, do n+1
        // coz for i=n/2 onwards (lower half) gives indices 1, 2 ... but we need 0, 1, 2
        for (int i=0; i < n; i++)
            nums[(1+2*i)%m] = sorted[i];
    }    
};

// For completeness, Time : O(n) average coz of nth_element;  Space : O(1)
// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// https://discuss.leetcode.com/topic/32893/o-n-time-and-cheating-o-1-space-solution-will-there-be-a-real-o-1-solution?show=77054
// https://discuss.leetcode.com/topic/32920/o-n-time-o-1-space-solution-with-detail-explanations
// https://discuss.leetcode.com/topic/41464/step-by-step-explanation-of-index-mapping-in-java

class Solution3 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};

// Time : O(n) average coz of nth_element;  Space : O(1)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
    
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        int i = (n - 1) / 2 * 2, j = i, k = 1;
        for (int c = 0; c < n; ++c) {
            if (nums[j] < mid) {
                swap(nums[i], nums[j]);
                i -= 2;
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            } 
            else if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k += 2;
            } 
            else {
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            }
        }
    }
};
