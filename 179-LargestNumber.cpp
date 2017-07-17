/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort (nums.begin(), nums.end(), [](int &i, int&j) {
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });
        
        // combine the numbers
        string res;
        for (const auto& n : nums) {
            res.append(to_string(n));
        }

        // special case: leading zeros (e.g. [0, 0])
        if (!res.empty() && res[0] == '0')  {
            return "0";
        }
        
        // this works too
        // while(res[0] == '0' && res.size()>1) res.erase(0,1);

        return res;            
    }
};
