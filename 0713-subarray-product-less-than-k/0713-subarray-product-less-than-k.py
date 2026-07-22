class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        count = 0
        product = 1
        left = 0
        for right in range(len(nums)):
            product *= nums[right]
            while product >= k:
                product /= nums[left]
                left += 1
            count += right - left +1 # all subarrays including new nums[right]
            # [1, 2] -> [1, 2, 3] ==> {[1, 2, 3], [2, 3], [3]} subarrays
        return count
