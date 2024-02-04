/*

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

// http://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
// http://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

// use hashtable
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) return intersection(nums2, nums1);
        unordered_set<int> s(nums1.cbegin(), nums1.cend());
        vector<int> res;
        
        for (const auto& e: nums2){
            if (s.find(e) != s.end()){ 
                res.push_back(e); 
                s.erase(e); // very important, else duplicate copies
            }
        }
        return res;
    }
};

// sort smaller array and binary search in this while traversing through bigger array
// erase-remove idiom : http://thispointer.com/removing-all-occurences-of-an-element-from-vector-in-on-complexity/
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());

        vector<int> result;
        for (const auto& i : nums2) {
            vector<int>::iterator it = lower_bound(nums1.begin(), nums1.end(), i);
            //vector<int>::const_iterator it = lower_bound(nums1.cbegin(), nums1.cend(), i);
            //auto it = lower_bound(nums1.cbegin(), nums1.cend(), i);
            
            if (it != nums1.end() && *it == i) {
                result.emplace_back(*it);
                nums1.erase(remove(nums1.begin(),nums1.end(),i),nums1.end()); //VERY IMP
            }
        }
        
        return result;
    }
};

// sort smaller and bigger array and iterate through them parallely
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } 
            else if (*it1 > *it2) {
                ++it2;
            } 
            else {
                if (result.empty() || result.back() != *it1) {
                    result.emplace_back(*it1);
                }
                ++it1, ++it2;
            }
        }
        return result;
    }
};

