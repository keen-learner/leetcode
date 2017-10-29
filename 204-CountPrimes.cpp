/*

Description:

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> s(n, true);
        if(n <2) return 0;
        else s[0] = s[1] = false;
        int count = n-2;
        
        for(int i = 2; i<n; i++) {
            if(s[i]) {
                for(int j = 2*i; j<n; j+=i) {
                    if(s[j]) {
                        s[j] = false; 
                        --count;
                    }
                }
            }
        }
        return count;
    }
};

class Solution1 {
public:
    int countPrimes(int n) {
        vector<bool> s(n, true);
        
        s[0] = false;
        s[1] = false;
        for(int i = 2; i<n; i++) {
            if(s[i]) {
                for(int j = 2*i; j<n; j+=i) s[j] = false;
            }
        }
        return count(s.begin(), s.end(), true);
    }
};
