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

// https://discuss.leetcode.com/topic/39755/proof-of-if-total-gas-is-greater-than-total-cost-there-is-a-solution-c?page=1
// https://discuss.leetcode.com/topic/1344/share-some-of-my-ideas?page=1

// Brute Force Solution
// Time Limit Exceeded
class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i<n; i++) { // try i as starting index
            int sum = 0;
            int j;
            for(j = i; j<i+n; j++) {
                int k = j%n;
                sum += gas[k] - cost[k];
                // cout<<"i "<<i<<" j "<<j<<" sum "<<sum<<endl;
                if(sum < 0) break;
            }
            if(j >= i+n) return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // case : [4], [5]
        // case : [1,2], [2,1]
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
            // i = (i +j + 1)%n;
            i = (i +j + 1);
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // case : [4], [5]
        // case : [1,2], [2,1]
        int sum = 0;
        int res = 0;
        int res_sum = INT_MAX;
        for(int i = 0; i<n; i++) { 
            sum += gas[i] - cost[i];
            if(sum < res_sum) {
                res_sum = sum;
                res = i+1;
            }
        }
        return sum>=0 ? res%n:-1;
    }
};


