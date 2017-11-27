/*

Find the length of the longest substring T of a given string (consists 
of lowercase letters only) such that every character in T appears no 
less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

// Time:  O(26 * n) = O(n)
// Space: O(26) = O(1)

// Recursive solution.
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, k, 0, s.size());
    }

private:
    int longestSubstringHelper(const string& s, int k, int start, int end) {
        vector<int> count(26);
        for (int i = start; i < end; ++i) {
            ++count[s[i] - 'a'];
        }
        
        int res = 0;
        for (int i = start; i < end;) {
            while (i < end && count[s[i] - 'a'] < k) {
                ++i;
            }
            if (i == end)  break;

            int j = i;
            while (j < end && count[s[j] - 'a'] >= k) {
                ++j;
            }
            if (i == start && j == end) {
                return end - start; 
            }

            res = max(res, longestSubstringHelper(s, k, i, j));
            i = j;
        }
        return res;
    }
};


// Better than 2 , but slower than above one
class Solution3 {
public:
    int longestSubstring(string s, int k) {
        // int res = 0;
        return longestSubstringHelper(s, k, 0, s.size()-1);
    }

private:
    int longestSubstringHelper(const string& s, int k, int start, int end) {
        if(end - start + 1 < k) return 0;
        // if(k == 0) return end-start+1; // not needed
        vector<int> count(26);
        for (int i = start; i <= end; ++i) {
            ++count[s[i] - 'a'];
        }

        int i = start;
        int res = 0;
        while(i<=end && count[s[i] - 'a']>=k) i++;
        if(i > end) return end - start + 1;
        res = max(res, longestSubstringHelper(s, k, start,i-1));
        // i's count < k
        return max(res, longestSubstringHelper(s, k, i+1, end));
    }
};

// Slow solution
class Solution2{
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        
        map<char,int> Map; // unordered map gave tle
        for(int i = 0; i < s.size(); i++){
            Map[s[i]]++;
        }
        
        int idx =0;
        while(idx <s.size() && Map[s[idx]] >= k)    idx++;
        if(idx == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);
        
        return max(left, right);   
    }    
};

// DOESN'T WORK
class Solution1 {
public:
    int longestSubstring(string s, int k) {
        /*  CASES
            "ababbc"
        */
        if(s.size()<k) return 0;
        map<char, int> m;
        int c = 0;
        int begin = 0;
        int end = 0;
        int res = 0;
        while(end < s.size()) {
            ++m[s[end]];
            if(m[s[end]] >= k) ++c;
            while(m.size() == c) {
                res = max(res, end - begin + 1);
                --m[s[begin]];
                if(m[s[begin]]<k) --c;
                ++begin;
            }
            ++end;
        }
        return res;
    }
};
