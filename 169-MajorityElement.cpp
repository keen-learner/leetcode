/*

Given an array of size n, find the majority element. The majority element is the element that 
appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

// http://www.geeksforgeeks.org/majority-element/

// O(n) solution using Voting Algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i<nums.size(); ++i) {
            if (nums[i] == candidate) count++;
            else if (count == 0) {
                candidate = nums[i]; count = 1;
            }
            else {
                --count;
            }
        }
        //check if majority element exists (not required for question as we know it exists)
        count = 0;
        for (int i = 0; i<nums.size(); ++i) {
            if (nums[i] == candidate) ++count;
        }
        if (count > nums.size()/2) return candidate;
        else return candidate; // in this case we know majority element
    }
};

// O(n) solution using Voting Algo
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i<nums.size(); ++i) {
            if (nums[i] == candidate) count++;
            else{
                --count;
                if (count == 0) {candidate = nums[i]; count = 1;}
            }
        }
        
        //check if majority element exists
        count = 0;
        for (int i = 0; i<nums.size(); ++i) {
            if (nums[i] == candidate) ++count;
        }
        if (count > nums.size()/2) return candidate;
        else return candidate; // in this case we know majority element
    }
};

// O(nlogn) divide and conquer solution
class Solution2 {
private:
    int getCount(vector<int>& a, int i, int j, int m ){
        int count = 0;
        for (int l = i; l<=j; l++){
            if (m == a[l]) ++count;
        }
        return count;
    }

    int mymajor(vector<int>& a,int i,int j ) {
        if (i == j) return a[i];
        int k = (i+j)/2;
        int n = j- i + 1;
        int m1 = mymajor(a, i, k);
        int m2 = mymajor(a, k+1, j);
        int c1 = -1, c2 = -1;
        if (m1 != INT_MIN) c1 = getCount(a, i, j, m1);
        if (m2 != INT_MIN) c2 = getCount(a, i, j, m2);
        if (c1 > n/2) return m1;
        if (c2 > n/2) return m2;
        return INT_MIN; // assuming INT_MIN will never be majority 
    }
public:
    int majorityElement(vector<int>& nums) {
        return mymajor(nums, 0, nums.size()-1);
    }
};

// genreic solution to get n/k major element
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int k = 2;
        const int n = nums.size();
        unordered_map<int, int> hash;

        for (const auto& i : nums) {
            ++hash[i];
            if (hash.size() == k) {
                auto it = hash.begin();
                while (it != hash.end()) {
                    if (--(it->second) == 0) {
                        hash.erase(it++);
                    } else {
                        ++it;
                    }
                }
            }
        }

        // Resets hash for the following counting.
        for (auto& it : hash) {
            it.second = 0;
        }

        // Counts the occurrence of each candidate integer.
        for (const auto& i : nums) {
            auto it = hash.find(i);
            if (it != hash.end()) {
                ++it->second;
            }
        }

        // Selects the integer which occurs > [n / k] times.
        vector<int> ret;
        for (const pair<int, int>& it : hash) {
            if (it.second > n / k) {
                ret.push_back(it.first);
                //ret.emplace_back(it.first);
            }
        }
        return ret[0];
    }
};
