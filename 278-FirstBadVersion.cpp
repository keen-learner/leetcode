/*

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all 
the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the 
first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether 
version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.

*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution1 {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid = low + (high-low)/2;
        while(1) {
            if(isBadVersion(mid)) {
                //if(!isBadVersion(mid-1)) return mid;
                //else high = mid-1;
                if(isBadVersion(mid-1)) high = mid-1;
                else return mid;
            }
            else low = mid+1;
            if(low>high) return low-1;
        }
    }
};

class Solution2 {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution3 {
public:
    int firstBadVersion(int n) {
        long l = 1, r = (long)n+1;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (!isBadVersion(m)) { //good version case
                l = m + 1;
            } 
            else {
                r = m;
            }
        }
        return l;
    }
};

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (!isBadVersion(m)) { //good version case
                l = m + 1;
            } 
            else {
                r = m;
            }
        }
        return l;
    }
};
