class Solution:
    def squaresum(self, num: int) -> int:
        result = 0
        while num:
            a = num%10
            result = result + a**2
            num = num//10
        return result
    def isHappy(self, n: int) -> bool:
        slow = self.squaresum(n)
        fast = self.squaresum(self.squaresum(n))
        while slow != fast:
            if fast == 1: return True
            slow = self.squaresum(slow)
            fast = self.squaresum(self.squaresum(fast))
        return fast == 1

        