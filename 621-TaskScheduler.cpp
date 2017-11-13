/*

Given a char array representing tasks CPU need to do. It contains 
capital letters A to Z where different letters represent different 
tasks.Tasks could be done without original order. Each task could be 
done in one interval. For each interval, CPU could finish one 
task or just be idle.

However, there is a non-negative cooling interval n that means 
between two same tasks, there must be at least n intervals that 
CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU 
will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(char ch:tasks) m[ch]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> maxpq; 
        
        for(auto it = m.begin(); it != m.end(); it++) {
            maxpq.push(make_pair(it->first, it->second));
        }
        
        int count = 0;
        while(!maxpq.empty()) {
            vector<pair<char, int>> temp;
            int k = n+1;
            while(k>0 && !maxpq.empty()) {
                auto top = maxpq.top();
                maxpq.pop();
                count ++;
                top.second--;
                temp.push_back(top);
                k--;
            }
            for(auto e:temp) {
                if(e.second > 0) maxpq.push(e);
            }
            if(!maxpq.empty()) count += k; // rest are idle slots
        }
        return count;
    }
    
    struct cmp {
        bool operator()(pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        }    
    };
};

