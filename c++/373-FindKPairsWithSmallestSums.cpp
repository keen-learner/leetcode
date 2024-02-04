/*

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

*/

class Solution {
    typedef vector<int>::iterator it;
    struct cmp{
        bool operator()(const pair<it,it>& a,const pair<it,it>& b){
            if(*(a.first) + *(a.second) == *(b.first) + *(b.second)) return *(a.first) > *(b.first);
            return *(a.first) + *(a.second) > *(b.first) + *(b.second);
        }
    };
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<it,it>,vector<pair<it,it>>,cmp> q; //min pq
        vector<pair<int,int>> res;
        auto it_1 = nums1.begin();
        auto it_2 = nums2.begin();
        if(it_1 == nums1.end() || it_2 == nums2.end()) return res;
        
        for( ; it_1 != nums1.end(); ++it_1) q.push(make_pair(it_1,it_2)); 
        
        while(!q.empty() && k > 0){
            k--;
            pair<it,it> tmp = q.top();
            q.pop();
            res.push_back(make_pair(*(tmp.first),*(tmp.second)));
            if(++tmp.second == nums2.end()) continue;
            q.push(make_pair(tmp.first,tmp.second));
            
        }
        return res;
    }
};

class Solution2 {
private:
    struct compare {
        bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
            return ((get<0>(t1) + get<1>(t1)) > (get<0>(t2) + get<1>(t2)));
        }
    };

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0) return ans;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, compare> pq;
        for(int i = 0; i < min((int)nums1.size(), k); i++) pq.push(make_tuple(nums1[i], nums2[0], 0));
        while(k-- > 0 && !pq.empty()) {
            tuple<int, int, int> top = pq.top();
            ans.push_back(make_pair(get<0>(top), get<1>(top)));
            pq.pop();
            if(get<2>(top) + 1 < nums2.size())
                pq.push(make_tuple(get<0>(top), nums2[get<2>(top)+1], get<2>(top)+1));
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty()) return {};
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxpq;
        for(int n1: nums1) {
            for(int n2: nums2) {
                maxpq.push({n1, n2});
                if (maxpq.size() > k) maxpq.pop();
            }
        }
        while(!maxpq.empty()) {
            res.push_back(maxpq.top());
            maxpq.pop();
        }
        return res;
    }
    
private:    
    struct compare{
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.first + a.second < b.first + b.second;
        }
    };    
};
