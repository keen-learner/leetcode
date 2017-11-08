/*

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -2^28 to 2^28 - 1 and the result is guaranteed to be at most 2^31 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/


// Time:  O(n^2)
// Space: O(n^2)

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> A_B_sum = new HashMap<>();
        for (int a : A) {
            for (int b : B) {
                A_B_sum.put(a + b, 1+A_B_sum.getOrDefault(a+b, 0));
            }
        }

        int res = 0;
        for (int c : C) {
            for (int d : D) {
                if (A_B_sum.containsKey(-c - d) ) {
                    res += A_B_sum.get(-c - d);
                }
            }
        }
        return res;        
    }
}
