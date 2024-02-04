/*

Suppose you have a random list of people standing in a queue. Each 
person is described by a pair of integers (h, k), where h is the 
height of the person and k is the number of people in front of this 
person who have a height greater than or equal to h. Write an 
algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

// Time : O(n^2)
// Space : O(n)
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.first>b.first || (a.first==b.first && a.second<b.second);
        });
        vector<pair<int, int>> res;
        for(auto p:people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

// for completeness
// Time:  O(n * sqrt(n))
// Space: O(n)
class Solution1 {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), 
            [](const pair<int, int>& a, pair<int, int>& b) {
                return b.first == a.first ? a.second < b.second : b.first < a.first;
            });

        vector<vector<pair<int, int>>> blocks(1);
        for (const auto& p : people) {
            auto index = p.second;
            int i = 0;
            for (; i < blocks.size(); ++i) {
                if (index <= blocks[i].size()) {
                    break;
                }
                index -= blocks[i].size();
            }
            blocks[i].emplace(blocks[i].begin() + index, p);
            
            if (blocks[i].size() * blocks[i].size() > people.size()) {
                blocks.emplace(blocks.begin() + i + 1,
                               blocks[i].begin() + blocks[i].size() / 2,
                               blocks[i].end());
                blocks[i].erase(blocks[i].begin() + blocks[i].size() / 2, blocks[i].end());
            }
        }

        vector<pair<int, int>> result;
        for (const auto& block : blocks) {
            for (const auto& p : block) {
                result.emplace_back(p);
            }
        }
        return result;
    }
};

