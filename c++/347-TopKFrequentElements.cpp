/*

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

// min heap so that when size > k, we know which element to remove i.e. topmost(min one using pop)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count; // num, count
        for(auto num : nums) ++count[num];
        
        struct compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first;
            }
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; //min pq
        for(auto it = count.begin(); it != count.end(); ++it) {
            pq.emplace(make_pair(it->second, it->first));
            if(pq.size() == k+1) pq.pop();
        }
        
        vector<int> res;
        // pq has no begin(), end()
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// Time:  O(nlogk)
// Space: O(n)
// Max Heap solution. NOTE: max heap used with keys -count
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        priority_queue<pair<int, int>> heap;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            heap.emplace(-(it->second), it->first);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }
        vector<int> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(n)
class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }

        vector<pair<int, int>> p;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            p.emplace_back(-(it->second), it->first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};

// bucket sort
class Solution4 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};


// quick selection
class Solution5 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<pair<int, int>> num_with_cnt;
        for (auto kv : cnt) {
            num_with_cnt.push_back({kv.first, kv.second});
        }
        kselection(num_with_cnt, 0, num_with_cnt.size()-1, k);
        for (int i = 0; i < k && i < num_with_cnt.size(); ++i) {
            res.push_back(num_with_cnt[i].first);
        }
        return res;
    }

    void kselection(vector<pair<int, int>>& data, int start, int end, int k) {

        if (start >= end) return;
        auto pv = data[end];
        int i = start;
        int j = start;
        while (i < end) {
            if (data[i].second > pv.second) {
                swap(data[i++], data[j++]);
            } else {
                ++i;
            }
        }
        swap(data[j], data[end]);
        int num = j - start + 1;
        if (num == k) return;
        else if (num < k) {
            kselection(data, j + 1, end, k - num);
        } else {
            kselection(data, start, j - 1, k);
        }
    }
};

