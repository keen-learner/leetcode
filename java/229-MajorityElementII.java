/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

*/

// http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

class Solution{
  public List<Integer> majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) return new ArrayList<Integer>();
        List<Integer> result = new ArrayList<Integer>();
        int number1 = nums[0], number2 = nums[0], count1 = 0, count2 = 0, len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] == number1)
                count1++;
            else if (nums[i] == number2)
                count2++;
            else if (count1 == 0) {
                number1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                number2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == number1)
                count1++;
            else if (nums[i] == number2)
                count2++;
        }
        if (count1 > len / 3)
            result.add(number1);
        if (count2 > len / 3)
            result.add(number2);
        return result;
    }    
}


class Solution1 {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int res1 = 0, res2 = 0;
        int c1 = -1, c2 = -1;
        for(int i = 0; i<n; i++) {
            if(c1 == -1) {
                c1 = 1;
                res1 = nums[i];
            }
            else if(nums[i] == res1) {++c1;}
            else if(c2 == -1) {
                c2 = 1;
                res2 = nums[i];
            }
            else if(nums[i] == res2) {
                ++c2;
            }
            else if (c1 == 0) {
                res1 = nums[i];
                ++c1;
            }
            else if (c2 == 0) {
                res2 = nums[i];
                ++c2;
            }
            else {
                --c1;
                --c2;
            }
        }
        c1 = 0; c2 = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == res1) ++c1;
            if(nums[i] == res2) ++c2;
        }
        List<Integer> res = new ArrayList<Integer>();
        if(c1>n/3) res.add(res1);
        if(c2>n/3 && res2!=res1) res.add(res2);
        return res;
    }
}
