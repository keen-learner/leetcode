'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        for i,k in enumerate(nums):
            if target - k in lookup:
                return [i, lookup[target-k]]
            lookup[k] = i       
        return []   

class Solution1(object):    
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i,k in enumerate(nums):
            tmp_nums = nums[i+1:]
            if target-k in tmp_nums:
                return [i, tmp_nums.index(target-k) + i+1]    
    
class Solution2(object):    
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # tmp = [(v,k) for k,v in enumerate(nums)]
        tmp2 = sorted([(v,k) for k,v in enumerate(nums)], key= lambda x: x[0])
        i = 0
        j = len(nums) - 1 
        while (i < j):
            if (tmp2[i][0] + tmp2[j][0] < target):
                i += 1
            elif(tmp2[i][0] + tmp2[j][0] > target):
                j -= 1    
            else:
                return[tmp2[i][1], tmp2[j][1]]
