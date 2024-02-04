/*

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; 
        for(int i = digits.size()-1; i>=0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry == 1) digits.insert(digits.begin(), carry);
        return digits;
    }
};

class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.cbegin(), digits.cend());
        int carry = 1;
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry == 1) {
            result.emplace(result.begin(), carry);
        }
        return result;  
    }
};

class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        //vector<int> result(digits.cbegin(), digits.cend());
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry == 1) {
            digits.emplace(digits.begin(), carry);
        }
        return digits;  
    }
};
