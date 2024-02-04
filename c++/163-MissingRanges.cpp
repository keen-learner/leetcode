/*

Given a sorted integer array where the range of elements are [0, 99] 
inclusive, return its missing ranges. 
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]

Example Questions Candidate Might Ask:

Q: What if the given array is empty?
A: Then you should return [“0->99”] as those ranges are missing.

Q: What if the given array contains all elements from the ranges?
A: Return an empty list, which means no range is missing.

*/

// Time:  O(n)
// Space: O(1)

class Solution3 {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        for (int i = 0, pre = lower - 1, cur = 0; i <= nums.size(); ++i, pre = cur) {
            if (i == nums.size()) {
                cur = upper + 1;
            } else {
                cur = nums[i];
            }
            if (cur - pre >= 2) {
                ranges.emplace_back(getRange(pre + 1, cur - 1));
            }
        }
        return ranges;
    }

    string getRange(const int lower, const int upper) {
        if (lower == upper) {
            return to_string(lower);
        } else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};

class Solution2 {
public:
  vector<string> missingRange(vector<int> a, int start, int end){
      vector<string> res;
      int prev = start - 1;
      for (int i = 0; i <= a.size(); i++) {
          int curr = (i == a.size()) ? end + 1 : a[i];
          if (curr - prev >= 2) {
              if (prev + 1 == curr - 1)
                  res.push_back(to_string(prev + 1));
              else
                  res.push_back(to_string(prev + 1)+"->"+to_string(curr - 1));
          }
          prev = curr;
      }
      return res;
  }
};

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int l = lower;
        for (int i = 0; i <= nums.size(); ++i) {
            int r = (i < nums.size() && nums[i] <= upper) ? nums[i] : upper + 1;
            if (l == r) ++l;
            else if (r > l) {
                res.push_back(r - l == 1 ? to_string(l) : to_string(l) + "->" + to_string(r - 1));
                l = r + 1;
            }
        }
        return res;
    }
};
