class Solution:
    def findComplement(self, num: int) -> int:
        res = 0
        t = 0
        while(num > 0):
            rightMostBit = num & 1
            if rightMostBit == 0:
                res += 2**t
            t += 1
            num = num >> 1
        return res
