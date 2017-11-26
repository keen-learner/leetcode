/*

Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for(int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; j--, k++) //odd length
                cut[k+1] = min(1+cut[j], cut[k+1]);
            // Following works too:
            // for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
            //     cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for(int j = i-1, k = i; j>=0 && k<n && s[j]==s[k]; j--, k++)
                cut[k+1] = min(1+cut[j], cut[k+1]);
            // Following works too:
            // for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
            //     cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};

class Solution1 {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n,0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            int temp = i;
            // for(int j = i; j >= 0; j--) {
            for(int j = 0; j <= i; j++) {
                if(s[j] == s[i] && ((i-j < 2) || pal[j + 1][i - 1])) {
                    pal[j][i] = true;  
                    temp = (j == 0 ? 0 : min(temp, cut[j - 1] + 1));
                }
            }
            cut[i] = temp;
        }
        return cut[n - 1];  
    }
};
