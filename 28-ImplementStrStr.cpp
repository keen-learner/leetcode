/*


Implement strStr().

Returns the index of the first occurrence of needle in 
haystack, or -1 if needle is not part of haystack.

*/

// Time:  O(n + k)
// Space: O(k)

// Wiki of KMP algorithm:
// http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// https://www.youtube.com/watch?v=KG44VoDtsAA

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m; ) {
            if (haystack[i] == needle[j]) { 
                i++;
                j++;
            }
            if (j == n) return i - j;
            if (i < m && haystack[i] != needle[j]) {
                if (j) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string& needle) {
        int n = needle.length();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len])
                lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
};

class Solution1 {
public:
    // int strStr(string haystack, string needle) {
    int strStr(string text, string pattern) { // text = haystack; pattern = needle
        if (pattern.empty()) return 0;
        // KMP ALGO:
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};


// Time:  O(n * k)
// Space: O(k)
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i + needle.size()-1 < haystack.size() + 1; ++i) {
            int j = 0;
            for(j = 0; j < needle.size(); j++) {
                if(needle[j] != haystack[i+j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};

// Time:  O(n * k)
// Space: O(k)
class Solution3 {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
