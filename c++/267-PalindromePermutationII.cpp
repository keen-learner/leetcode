/*

Given a string s, return all the palindromic permutations (without duplicates) of it. 
Return an empty list if no palindromic permutation could be form.
For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].
Hint:
If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a 
similar approach from: Permutations II or Next Permutation.

*/

// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }

        unordered_map<char, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }

        string mid, chars;
        for (const auto& kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.push_back(kvp.first);
                } else {  // The count of the middle char is at most one. 
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }
        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string& mid, string& chars) {
        vector<string> result;
        sort(chars.begin(), chars.end());
        do {
            string reverse_chars(chars.crbegin(), chars.crend());
            result.emplace_back(chars + mid + reverse_chars);
        } while (next_permutation(chars.begin(), chars.end()));
        return result;
    }
};

class Solution2 {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }

        unordered_map<char, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }

        string mid, chars;
        for (const auto& kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.append(1, kvp.first);
                } else {  // The count of the middle char is at most one. 
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }

        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string& mid, string& s) {
        vector<string> result;
        vector<bool> used(s.length(), false);
        string ans;

        sort(s.begin(), s.end());
        permuteUniqueRecu(mid, s, &used, &ans, &result);
        return result;
    }

    void permuteUniqueRecu(const string& mid, const string& s, vector<bool> *used,
                           string *ans, vector<string> *result) {
        if (ans->length() == s.length()) {
            string reverse_ans(ans->crbegin(), ans->crend());
            result->emplace_back(*ans + mid + reverse_ans);
            return;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (!(*used)[i] && !(i != 0 && s[i - 1] == s[i] && (*used)[i - 1])) {
                (*used)[i] = true;
                ans->push_back(s[i]);
                permuteUniqueRecu(mid, s, used, ans, result);
                ans->pop_back();
                (*used)[i] = false;
            }
        }
    }
};

// http://www.cnblogs.com/grandyang/p/5315227.html

class Solution1 {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return res;
    }

    void permute(string &t, int start, string mid, vector<string> &res) {
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        } 
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[i], t[start]);
            permute(t, start + 1, mid, res);
            swap(t[i], t[start]);
        }
    }
};

/*

The following method is very similar to the above method, the difference is that the 
method of arrangement is slightly different, the above method is through the exchange of 
characters to generate a different character string, and the following method is 
by adding different Of the characters to generate a full array of strings, see the code as follows:

*/


class Solution2 {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        
        for (auto &it : m) {
            if (it.second % 2 == 1) mid += it.first;
            it.second /= 2;
            t += string(it.second, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, m, mid, "", res);
        return res;
    }
    void permute(string &t, unordered_map<char, int> &m, string mid, string out, vector<string> &res) {
        if (out.size() >= t.size()) {
            res.push_back(out + mid + string(out.rbegin(), out.rend()));
            return;
        } 
        for (auto &it : m) {
            if (it.second > 0) {
                --it.second;
                permute(t, m, mid, out + it.first, res);
                ++it.second;
            }
        }
    }
};

class Solution3 {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        sort(t.begin(), t.end());
        do {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        } while (next_permutation(t.begin(), t.end()));
        return res;
    }
};
