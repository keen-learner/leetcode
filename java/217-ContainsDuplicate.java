/*

Given an array of integers, find if the array contains any duplicates. Your function should 
return true if any value appears at least twice in the array, and it should 
return false if every element is distinct.

*/

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int i = 0; i<nums.length; i++) {
            s.add(nums[i]);
        }
        return s.size() != nums.length;
    }
}

class Solution2 {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0; i<nums.length-1; i++) {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
}

/*

// Brute Force; TLE solution

class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        for(int i = 0; i<nums.length-1; i++) {
            for(int j = i+1; j<nums.length; j++){
               if(nums[i] == nums[j]) return true;    
            }
        }
        return false;
    }
}
*/



