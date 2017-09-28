/*

Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int l = 1, r = x/2;
        while(l < r) {
            int m = l + (r-l+1)/2;
            if((long)m*m > x) r = m-1;
            else l = m;
        }
        return l;
        // return l*l<=x?l:l-1; // l*l is always <= x
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 1, right = x/2;
        //int left = 1, right = x;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            //long t = mid*mid; gives error with this
            long t = mid*(long(mid));
            if (t > x ) {
            //if ((long)mid*mid > x ) { //this works too
                right = mid - 1;
            } 
            else if(t < x){
            //else if((long)mid*mid < x){ //this works too
                left = mid + 1;
            }
            //else if(t == (long)x )return mid;
            else return mid;
            //else if((long)mid*mid == x )return mid;
        }
        return left-1;
        //return right;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int left = 1, right = x/2;
        //int left = 1, right = x;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            //if (mid >= x / mid) {
            if (mid > x / mid) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        //return left-1;
        return right;
    }
};

class Solution3 {
public:
    int mySqrt(int x) {
        long long high = x;
        long long low = 0;
        if (x<=0) {return 0;}
        if (x==1) {return 1;}
        while (high-low >1){
            long long mid = low + (high-low)/2;
            if (mid*mid<=x){low = mid;}
            else {high = mid;}
        }
        return low;
    }
};
