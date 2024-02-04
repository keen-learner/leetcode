/*

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

*/

class Solution {
public:
    Solution(vector<int> nums) {
        orig = nums;
        cpy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return cpy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = orig.size()-1; i >= 0; i--) {
            int index = rand() % (i+1);
            swap(orig[i], orig[index]);
        }
        return orig;
    }
private:
    vector<int> orig;
    vector<int> cpy;
};


// http://www.geeksforgeeks.org/shuffle-a-given-array/
// Time:  O(n)
// Space: O(n)

class Solution1 {
public:
    Solution1(vector<int> nums) : nums_(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(nums_);
        default_random_engine seed( (random_device())() );
        for (int i = 0; i < nums.size(); ++i) {
            //swap(nums[i],  nums[uniform_int_distribution<int>{i, static_cast<int>(nums.size()) - 1}(seed)]);
            swap(nums[i],  nums[uniform_int_distribution<int>{i, nums.size() - 1}(seed)]);
        }
        return nums;
    }

private:
    const vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
