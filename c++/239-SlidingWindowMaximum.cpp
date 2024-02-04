/*

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

*/

class Monoqueue {
    deque<pair<int, int>> m_deque; //pair.first: the actual value, 
                                   //pair.second: how many elements were deleted between it and the one before it.
    public:
        void push(int val)
        {
            int count = 0;
            while(!m_deque.empty() && m_deque.back().first < val)
            {
                count += m_deque.back().second + 1;
                m_deque.pop_back();
            }
            m_deque.emplace_back(val, count);
        };
        int max()
        {
            return m_deque.front().first;
        }
        void pop ()
        {
            if (m_deque.front().second > 0)
            {
                m_deque.front().second --;
                return;
            }
            m_deque.pop_front();
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        Monoqueue mq;
        k = min(k, (int)nums.size());
        int i = 0;
        for (;i < k - 1; ++i) //push first k - 1 numbers;
        {
            mq.push(nums[i]);
        }
        for (; i < nums.size(); ++i)
        {
            mq.push(nums[i]);            // push a new element to queue;
            results.push_back(mq.max()); // report the current max in queue;
            mq.pop();                    // pop first element in queue;
        }
        return results;        
    }
};

// Time:  O(n)
// Space: O(k)
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> max_numbers;

        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            if (i >= k && !dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                max_numbers.emplace_back(nums[dq.front()]);
            }
        }

        return max_numbers;
    }
};


class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win(nums.begin(), nums.begin()+k);
        vector<int> res;
        
        if(nums.empty() || k > nums.size() || k < 0) return res;
        
        res.push_back(*win.rbegin());
        for (int i = k; i < nums.size(); ++i) {
            if(win.count(nums[i-k]) > 1) {
                win.erase(nums[i-k]);
                win.insert(nums[i-k]);
            } else {
                win.erase(nums[i-k]);
            }
            
            // win.erase(nums[i-k]);
            win.insert(nums[i]);
            res.push_back(*win.rbegin());
        }
        return res;
    }
};
