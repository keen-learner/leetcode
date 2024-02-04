/*

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in 
the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size();
        int left, right, sum;
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        for (int i = 0; i < len - 3; ++i) {
            if (i && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 2; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                sum = target - num[i] - num[j];
                left = j + 1, right = len - 1;
                while (left < right) {
                    if (num[left] + num[right] == sum) {
                        res.push_back({num[i], num[j], num[left], num[right]});
                        ++left, --right;
                        while (left < right && num[left] == num[left - 1]) {
                            ++left;
                        }
                        while (left < right && num[right] == num[right + 1]) {
                            --right;
                        }
                    } 
                    else {
                        if (num[left] + num[right] > sum) {
                            --right;
                        } 
                        else {
                            ++left;
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size();
        int left, right, sum;
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        for (int i = 0; i < len - 3; ++i) {
            if (i && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 2; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                sum = target - num[i] - num[j];
                for(left = j+1, right = len-1; left < right;) {
                    if(left > j+1 && (num[left] == num[left-1])) ++left;
                    else if(right+1 < len &&(num[right] == num[right+1])) --right;
                    else {
                        if(num[left]+num[right] > sum) --right;
                        else if (num[left]+num[right] < sum) ++left;
                        else {
                            res.push_back({num[i], num[j], num[left], num[right]});
                            ++left, --right;    
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
class Solution3 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        if (num.size() < 4)  {
            return res;
        }
        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int, int>> cache;

        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                cache.emplace(num[i] + num[j], make_pair(i, j));
            }
        }

        for (auto i = cache.begin(); i != cache.end(); ++i) {
            auto a = i->second.first;
            auto b = i->second.second;
            auto range = cache.equal_range(target - i->first);
            for (auto j = range.first; j != range.second; ++j) {
                auto c = j->second.first;
                auto d = j->second.second;
                if (b < c) {
                    res.push_back({num[a], num[b], num[c], num[d]});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
