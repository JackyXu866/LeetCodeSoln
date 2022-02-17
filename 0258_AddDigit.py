class Solution:
    # math
    def addDigits(self, num: int) -> int:
        return 1 + (num - 1) % 9 if num else 0
