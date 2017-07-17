/*

Given an array of meeting time intervals consisting of start and end 
times [[s1,e1],[s2,e2],...] (si < ei), find the minimum 
number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

*/

/*
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
*/

// min priority queue
class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(begin(intervals), end(intervals), [](Interval& a, Interval& b) {return a.start < b.start;});
    priority_queue<int, vector<int>, greater<int>> pq;
    for (size_t i = 0; i < intervals.size(); ++i) {
      if (!pq.empty() && pq.top() <= intervals[i].start) pq.pop();
      pq.push(intervals[i].end);
    }
    return pq.size();
  }
};


// 2 separate vectors
class Solution1 {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (const auto& i : intervals) {
            starts.emplace_back(i.start);
            ends.emplace_back(i.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int min_rooms = 0, cnt_rooms = 0;
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                ++cnt_rooms;  // Acquire a room.
                // Update the min number of rooms.
                min_rooms = max(min_rooms, cnt_rooms);
                ++s;
            } else {
                --cnt_rooms;  // Release a room.
                ++e;
            }
        }
        return min_rooms;
    }
};

// map is sorted, keep track of changes(+1, -1)
class Solution2{
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> changes;
    for (auto i : intervals) {
        changes[i.start] += 1;
        changes[i.end] -= 1;
    }
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        maxrooms = max(maxrooms, rooms += change.second);
    return maxrooms;
  }

};
