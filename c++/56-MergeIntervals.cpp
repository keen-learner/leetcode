/*

Given a collection of intervals, merge 
all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// // NOTE: [1,4], [4,5] => [1,5]

class Solution {

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;               
            });

        vector<Interval> result{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= result.back().end) { 
                result.back().end = max(result.back().end, intervals[i].end);
            } 
            else {
                result.emplace_back(intervals[i]);
            }
        }
        return result;
    }
};
