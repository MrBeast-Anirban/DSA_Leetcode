class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start = 0
        minLen = float('inf')
        windowSum = 0
        for end in range(len(nums)):
            windowSum += nums[end]
            while windowSum >= target:
                minLen = min(minLen, end-start+1)
                windowSum -= nums[start]
                start += 1
        return minLen if minLen != float('inf') else 0
