/*

Given a non-empty string str and an integer k, rearrange the 
string such that the same characters are at least distance 
k from each other.

All input strings are given in lowercase letters. If it is not 
possible to rearrange the string, return an empty string "".

Example:

str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.

*/


// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string rearrangeString(string str, int k) {
        int cnts [26] = {0};
        for (int i = 0;  i < str.length(); ++i) {
            ++cnts[str[i] - 'a'];
        }

        vector<pair<int, char>> sorted_cnts;
        for (int i = 0; i < 26; ++i) {
            sorted_cnts.emplace_back(cnts[i], i + 'a');
        }
        sort(sorted_cnts.begin(), sorted_cnts.end(), greater<pair<int, int>>());

        const auto max_cnt = sorted_cnts[0].first;
        string blocks[max_cnt];
        int i = 0;
        for (const auto& cnt : sorted_cnts) {
            for (int j = 0; j < cnt.first; ++j) {
                blocks[i].push_back(cnt.second);
                i = (i + 1) % max(cnt.first, max_cnt - 1);
            }
        }

        string result;
        for (int i = 0; i < max_cnt - 1; ++i) {
            if (blocks[i].length() < k) {
                return "";
            } else {
                result += blocks[i];
            }
        }
        result += blocks[max_cnt - 1];
        return result;
    }
};

// Time:  O(nlogc), c is the count of unique characters.
// Space: O(c)
class Solution2 {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) {
            return str;
        }

        unordered_map<char, int> cnts;
        for (const auto& c : str) {
            ++cnts[c];
        }

        priority_queue<pair<int, char>> heap; // max pq
        for (const auto& kvp : cnts) {
            heap.emplace(kvp.second, kvp.first);
        }

        string result;
        while (!heap.empty()) {
            vector<pair<int, char>> used_cnt_chars;
            int cnt = min(k, static_cast<int>(str.length() - result.length()));
            for (int i = 0; i < cnt; ++i) {
                if (heap.empty()) {
                    return "";
                }
                auto top = heap.top();
                heap.pop();
                result.push_back(top.second);
                if (--top.first > 0) {
                    used_cnt_chars.emplace_back(move(top));//optimization, move instead of copy
                }
            }
            for (auto& cnt_char: used_cnt_chars) {
                heap.emplace(move(cnt_char));//optimization, move instead of copy
            }
        }
        return result;
    }
};
