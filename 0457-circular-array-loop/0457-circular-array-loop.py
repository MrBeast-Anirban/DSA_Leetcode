class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        def nextIndex(i):
            return (i+nums[i])%n
        for i in range (n):
            if nums[i] == 0:
                continue
            slow, fast = i, i
            while nums[slow] * nums[nextIndex(fast)] > 0 and nums[slow] * nums[nextIndex(nextIndex(fast))] > 0:
                slow = nextIndex(slow)
                fast = nextIndex(nextIndex(fast))
                if slow == fast:
                    if slow == nextIndex(slow): # self loop not a real cycle
                        break
                    return True
            j = i
            while nums[j] * nums[nextIndex(j)] > 0:
                next_j = nextIndex(j)
                nums[j] = 0
                j = next_j
        return False

            