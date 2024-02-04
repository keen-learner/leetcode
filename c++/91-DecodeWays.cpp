/*

A message containing letters from A-Z is being encoded 
to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine 
the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        if(s.size() == 1) {
            if(s[0]>='1' && s[0]<='9') return 1;
        }
        int fn_2 = 0;
        int fn_1 = 1;
        int fn = 0;

        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    fn = i-2>=0 ? fn_2:1;
                }
                else fn = 0;
            }
            else { // s[i] = [1,9]
                fn = fn_1;
                if(s[i-1] == '1' || (s[i-1] == '2' && (s[i] <= '6' && s[i] >= '1')) ) {
                    fn += (i-2>=0 ? fn_2 : 1);
                }
            }
            // cout<<"i = "<<i<<" s[i] = "<<s[i]<<" fn_2 = "<<fn_2<<" fn_1 = "<<fn_1<<" fn = "<<fn<<endl;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution1 {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int fn_2 = 0;
        int fn_1 = 1; 
        int fn = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                fn_1 = 0; // f[n - 1] = 0
            }
            if (!(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                fn_2 = 0; // f[n - 2] = 0
            }
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        dp[0] = 1;

        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == '0') {
                // improving this case
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = i-2>=0 ? dp[i-2]:1;
                }
            }
            else { // s[i] = [1,9]
                dp[i] = dp[i-1];
                if(s[i-1] == '1' || (s[i-1] == '2' && (s[i] <= '6' && s[i] >= '1')) ) {
                    dp[i] += (i-2>=0 ? dp[i-2] : 1);
                }
            }
        }
        return dp[s.size()-1];
    }
};

class Solution3 {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        dp[0] = 1;

        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == '0') {
                // if(s[i-1] > '2' || s[i-1] < '1') dp[i] = 0;
                // else { // s[i-1] = 1 or 2
                //     if(i-2>=0) dp[i] = dp[i-2];
                //     else dp[i] = 1;
                // }
                // improving this case
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = i-2>=0?dp[i-2]:1;
                } // else default dp[i] = 0
            }
            else { // s[i] = [1,9]
                dp[i] = dp[i-1];
                
                if(s[i-1] == '1') { 
                    // if(i-2>=0) dp[i] += dp[i-2];
                    // else dp[i] += 1;
                    dp[i] += (i-2>=0 ? dp[i-2] : 1);
                }
                else if(s[i-1] == '2') { 
                    if(s[i] <= '6' && s[i] >= '1' ) {
                        // if(i-2>=0) dp[i] += dp[i-2];
                        // else dp[i] += 1;
                        dp[i] += (i-2>=0 ? dp[i-2] : 1);
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};


