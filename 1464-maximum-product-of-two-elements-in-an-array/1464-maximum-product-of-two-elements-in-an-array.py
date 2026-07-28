class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return -1
        nums.sort()
        return (nums[-2]-1)*(nums[-1]-1)
        