/*

Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {
    public int mySqrt(int x) {
        if(x <= 1) return x;
        int l = 1, r = x/2;
        while(l < r) {
            int m = l + (r-l+1)/2;
            if((long)m*m > x) r = m-1;
            else l = m;
        }
        return l;        
    }
}
