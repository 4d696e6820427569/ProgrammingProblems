class Solution:
    def titleToNumber(self, s: str) -> int:
        i = len(s)-1
        res = 0
        while(i >= 0):
            res += 26 ** (len(s) - 1 - i) * (ord(s[i]) - ord('A') + 1)
            i -= 1
        return res