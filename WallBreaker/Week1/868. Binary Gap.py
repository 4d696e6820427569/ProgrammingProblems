class Solution:
    def binaryGap(self, N: int) -> int:
        maxD = 0
        firstOne = True
        curDist = 0
        while(N > 0):
            curBit = N & 1
            if firstOne:
                if curBit == 1:
                    firstOne = False
            else:
                curDist += 1
                if curDist > maxD:
                    maxD = curDist

                if curBit == 1:
                    curDist = 0

            N = N >> 1

        return maxD
