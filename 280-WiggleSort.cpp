/*

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

*/



// Time Complexity O(nlgn)
/*

sort elements
we want like this: 
a[0]      a[1]    a[3]
     a[2]     a[4]

To achieve this:
for nth element where n:3, 5, 7 ...
swap nth and n-1th element  

*/
class Solution1 {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return;
        for (int i = 2; i < nums.size(); i += 2) {
            swap(nums[i], nums[i - 1]);
        }
    }
};

/*

A[0] <= A[1] >= A[2] <= A[3] >= A[4] <= A[5]
So we could actually observe that there is pattern that
A[even] <= A[odd],
A[odd] >= A[even].

*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (((i % 2) && nums[i] < nums[i - 1]) ||
                (!(i % 2) && nums[i] > nums[i - 1])) {
                // Swap unordered elements.
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
