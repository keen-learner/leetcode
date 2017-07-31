/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

// NOTE: [1,4], [4,5] => [1,5]
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        if(intervals.isEmpty()) return res;
        intervals.sort(new Comparator<Interval>() {
            public int compare(Interval i1, Interval i2) {
                if(i1.start < i2.start) return -1;
                else if(i2.start < i1.start) return 1;
                else return 0;
            }
        });
        res.add(intervals.get(0));
        for(int i = 1; i< intervals.size(); i++) {
            Interval t = intervals.get(i);
            if(t.start > res.get(res.size()-1).end) {
                res.add(t);
            }
            else {
                Interval back = res.get(res.size()-1);
                back.end = Math.max(back.end, t.end);
            }
        }
        return res;
    }
}
