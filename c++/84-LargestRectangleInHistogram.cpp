/*

Given n non-negative integers representing the histogram's bar height where the width 
of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        for(int i = 0; i <= heights.size(); ) {
            if(s.empty() || (i<heights.size() && heights[i] > heights[s.top()])) {
                s.push(i);
                i++;
            } 
            else {
                int h = heights[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();;
                res = max(res, h * (i -1 - l));
            }
        }
        return res;
    }
};

