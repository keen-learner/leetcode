/*

Description:

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
    public int countPrimes(int n) {
        boolean[] s = new boolean[n];
        Arrays.fill(s, true);
        if(n>2) s[0] = s[1] = false;
        else return 0;
        int count = n-2; // for 0 and 1
        for(int i = 2; i<n; i++) {
            if(s[i]) {
                for(int j = 2*i; j<n; j+=i) {
                    if(s[j]){
                        s[j] = false;
                        --count;
                    }
                }
            }
        }
        return count;
    }
}
