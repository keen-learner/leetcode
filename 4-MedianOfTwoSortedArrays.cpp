/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run 
time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

// Time:  O(log(min(m, n)))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if ((a.size() + b.size()) % 2 == 1) { //odd elements
            return helper(a, 0, a.size()-1, b, 0, b.size()-1, (a.size() + b.size()) / 2 + 1);
        } else { //even elements
            return (helper(a, 0, a.size()-1, b, 0, b.size()-1, (a.size() + b.size()) / 2) +
                    helper(a, 0, a.size()-1, b, 0, b.size()-1, (a.size() + b.size()) / 2 + 1)) / 2.0;
        }
    }

private:    
    double helper(const vector<int>& a, int as, int ae, const vector<int>& b,
                                 int bs, int be, int k) { //kth order statistic
        
        auto m = ae - as + 1; 
        auto n = be - bs + 1;
        if (m > n)
            return helper(b, bs, be, a, as, ae, k);
        if (m <= 0)
            return b[bs + k - 1];
        if (k == 1)
            return min(a[as], b[bs]);
        auto k1 = min(k/2, m); // key point
        auto k2 = k - k1;
        if (a[as+k1-1] <= b[bs+k2-1])
            return helper(a, as+k1, ae, b, bs, bs+k2-1, k-k1);
        return helper(a, as, as+k1-1, b, bs+k2, be, k-k2);
    }
};


class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus left is the (k + 1)-th element.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }
};

// Time:  O(log(max(m, n)) * log(max_val - min_val))
// Space: O(1)
// Generic solution.
class Solution_Generic {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> *> arrays{&nums1, &nums2};
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2) +
                    findKthInSortedArrays(arrays, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthInSortedArrays(const vector<vector<int> *>& arrays, int k) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        for (const auto array : arrays) {
            if (!array->empty()) {
                left = min(left, array->front());
                right = max(right, array->back());
            }
        }
        // left xxxxxxxooooooo right, find first xo or oo
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (match(arrays, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        // case: xoo
        //        ^^
        if (match(arrays, left, k)) {
            return left;
        }
        // case: xo
        //       ^^
        return right;
    }

    bool match(const vector<vector<int> *>& arrays, int num, int target) {
        int res = 0;
        for (const auto array : arrays) {
            if (!array->empty()) {
                res += distance(upper_bound(array->cbegin(), array->cend(), num),
                                array->cend());
            }
        }
        return res < target;
    }
};
