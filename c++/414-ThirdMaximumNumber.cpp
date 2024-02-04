/*

Given a non-empty array of integers, return the third maximum number 
in this array. If it does not exist, return the maximum number. 
The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};

// DOESN'T WORK
class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        /* CASES :
            [1,2,-2147483648] // fail
            [-2147483648,1,2] // fail
            [1,-2147483648,2]
            [2,2,1,3]
            [-2147483648,1,1]
        */

        int count = 0;
        vector<int> top(3, numeric_limits<int>::min());

        for (const auto& num : nums) {
            if (num > top[0]) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = num;
                ++count;
            } 
            else if (num != top[0] && num > top[1]) {
                top[2] = top[1];
                top[1] = num;
                ++count;
            } 
            else if ((num != top[0] && num != top[1]) && num >= top[2]) {
                top[2] = num;
                ++count;
            }
        }

        if (count < 3) { 
            return top[0];
        }
        return top[2];
        
    }
};

class Solution1 {
public:    
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for (int num : nums) {
            top3.insert(num);
            if (top3.size() > 3)
                top3.erase(top3.begin());
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};

