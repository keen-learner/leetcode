/*

Given an array of integers Aand integers K, the maximum return Sso that there is i < j, A[i] + A[j] = Sand S < K. If equation is met does not exist iand jreturns -1.

Sample
输入：A = [34,23,1,24,75,33,54,8], K = 60
输出：58
解释：
34 和 24 相加得到 58，58 小于 60，满足题意。
输入：A = [10,20,30], K = 15
输出：-1

prompt
1 <= A.length <= 100
1 <= A[i] <= 1000
1 <= K <= 2000

algorithm
(violent enumeration) O ( n2)O(n2)
Violence enumeration iand jthen find less than Kthe maximum value in the case of.

time complexity
Two layers of loop traversal, so the time complexity is O ( n2)O(n2).

Space complexity
Only a constant traversal is required, so the space complexity is O ( 1 )O(1).

*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int n = A.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (A[i] + A[j] < K)
                    ans = max(ans, A[i] + A[j]);

        return ans;
    }
};

