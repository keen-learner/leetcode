/*

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel 
from station i to its next station (i+1). You begin the journey with an empty 
tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, 
otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int sum = 0;
        int res = 0;
        int res_sum = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++) { 
            sum += gas[i] - cost[i];
            if(sum < res_sum) {
                res = i+1;
                res_sum = sum;
            }
        }
        return sum < 0 ? -1 : res%n;
    }
}

class Solution2 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        for(int i = 0; i<n; ) { // try i as starting index
            int sum = 0;
            int j;
            for(j = 0; j<n; j++) {
                int k = i + j;
                k = k%n;
                sum += gas[k] - cost[k];
                // cout<<"i "<<i<<" j "<<j<<" sum "<<sum<<endl;
                if(sum < 0) break;
            }
            if(j >=n) return i;
            i = (i +j + 1);
        }
        return -1;
    }
}

// Brute force , TLE
class Solution1 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        for(int i = 0; i<n; i++) { //try i as starting index
            int sum = 0;
            int j = 0;
            for(j = 0; j<n; j++) {
                int k = (i+j)%n;
                sum += gas[k] - cost[k];
                if(sum < 0) break;
            }
            if(j==n) return i;
        }
        return -1;
    }
}
