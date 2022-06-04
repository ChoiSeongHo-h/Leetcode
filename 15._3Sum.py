"""
https://github.com/TAVE-7-python-algorithm-study/algorithm-interview
-> 9 세 수의 합 (★★/★★★)

https://leetcode.com/problems/3sum/
"""

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []

        if len(nums) < 3 :
            return output

        for i in range(0, len(nums)-2) :
            for j in range(i+1, len(nums)-1) :
                for k in range(j+1, len(nums)) :
                    if nums[i]+nums[j]+nums[k] == 0 :
                        tempList = sorted([nums[i], nums[j], nums[k]])
                        if tempList not in output :
                            output.append(tempList)

        return output