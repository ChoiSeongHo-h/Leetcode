"""
https://github.com/TAVE-7-python-algorithm-study/algorithm-interview
-> 11 자신을 제외한 배열의 곱 (★★/★★★)

https://leetcode.com/problems/product-of-array-except-self/
-> Accepted
"""

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr0 = [1]
        arr1 = [1]
        for i in range(0, len(nums)-1) :
            arr0.append(arr0[-1]*nums[i])
        tempNums = list(reversed(nums))
        for i in range(0, len(tempNums)-1) :
            arr1.append(arr1[-1]*tempNums[i])
        arr1.reverse()
        for i in range(0, len(arr0)) :
            arr0[i] = arr0[i]*arr1[i]

        return arr0