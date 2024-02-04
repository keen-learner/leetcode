/*

Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap 
after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

/*
Idea is to calculate unit of water at evry index.
At i, find tallest bar to left and right.
Water at i is the difference between height[i] and min(left, right)  

*/

/*
[2,3] -> 0
[2,0,3] -> 2
[2,0,2] -> 2
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0;                 // highest wall
        int water = 0;
        int l = 0, r = height.size() - 1;   // pointers
        while (l <= r) {
            if (lmax < rmax) {
                water += max(lmax - height[l], 0);
                lmax = max(lmax, height[l]);
                ++l;
            } else {
                water += max(rmax - height[r], 0);
                rmax = max(rmax, height[r]);
                --r;
            }
        }

        return water;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        const auto n = height.size();
        if(n == 0) return 0;
        int l = 0;
        int r = n-1;
        int left_max = height[0];
        int right_max = height[n-1];

        int water = 0;
        while(l < r) {
            if (height[l] < height[r]) {
                height[l] >= left_max ? (left_max = height[l]) : water += (left_max - height[l]);
                ++l;
            }
            else {
                height[r] >= right_max ? (right_max = height[r]) : water += (right_max - height[r]);
                --r;
            }
        }
        return water;
        
        
    }
};

class Solution1 {
public:
    int trap(vector<int>& height) {
        const auto n = height.size();
        if(n == 0) return 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        for(int i = 1; i < n; ++i) {
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i = n-2; i > -1; --i) {
            right[i] = max(height[i], right[i+1]);
        }
        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
        
        
    }
};
