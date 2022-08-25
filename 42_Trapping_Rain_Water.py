"""
https://leetcode.com/problems/trapping-rain-water/
-> Time Limit Exceeded (Hard)
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        output = 0
        if len(height) <= 2:
            return output

        i = 0
        while i < len(height) - 2:
            if height[i + 1] >= height[i]:
                i = i + 1
                continue

            localMax = -1
            localMaxIdx = -1
            j = i + 2

            # 1. larger than height[i] case 
            while j < len(height):
                if height[j] > localMax:
                    localMax = height[j]
                    localMaxIdx = j

                    if height[j] >= height[i]:
                        for k in range(i + 1, j):
                            output = output + height[i] - height[k]
                        i = j - 1
                        break
                j = j + 1

                # 2. smaller than height[i] case
                if j == len(height):
                    for k in range(i + 1, localMaxIdx):
                        if localMax > height[k]:
                            output = output + localMax - height[k]
                    i = localMaxIdx - 1
            i = i + 1
        return output
