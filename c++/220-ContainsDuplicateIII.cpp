/*

Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the absolute difference between nums[i] and nums[j] is at most 
t and the absolute difference between i and j is at most k.

*/


// Time:  O(nlogk)
// Space: O(k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) {
            return false;
        }
        
        queue<int64_t> window;
        multiset<int64_t> bst;
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements.
            if (bst.size() > k) {
                int num = window.front();
                window.pop();
                bst.erase(bst.find(num));
            }
            // Every search costs time: O(logk).
            const auto it = bst.lower_bound(nums[i] - t);
            if (it == bst.cend() || (*it - nums[i]) > t) {
                // Not found.
                window.emplace(nums[i]);
                bst.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    static bool pcomp(pair<int,int> a, pair<int,int> b) {
        return a.first < b.first ;
    }
     
    bool search(vector<pair<int,int> > l, int t, int k){
        int po = 0;
        while (po < l.size()){
            int i = po + 1;
            while (i < l.size()){
                if ((abs(long(l[i].first) - long(l[po].first)) <= t)&&(abs(l[i].second - l[po].second)<= k)){
                    return true;
                }else{
                    if (abs(long(l[i].first) - long(l[po].first)) > t){
                        break;
                    }else{
                        i+=1;
                    }
                }
            }
            po += 1;
        }
        return false;
    }
     
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 ){
            return false;
        }
        vector<pair<int,int> > pp;
        for (int i=0;i<nums.size();i++){
            pp.push_back(make_pair(nums[i], i));
        }
        sort(pp.begin(),pp.end(),pcomp);
        return search(pp, t, k);
    }
};
