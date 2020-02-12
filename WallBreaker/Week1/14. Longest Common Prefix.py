class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if (len(strs) == 0):
            return ""
        longestCommonPref = ""
        
        minLenIndex = 0;
        for i in range(1, len(strs), 1):
            if (len(strs[i]) < len(strs[minLenIndex])):
                minLenIndex = i
                
        i = 0
        wordMinLen = strs[minLenIndex]
        while (i < len(wordMinLen)):
            curChar = wordMinLen[i]
            for j in range(len(strs)):
                if (j == minLenIndex):
                    continue
                if (curChar != strs[j][i]):
                    return longestCommonPref
            longestCommonPref += wordMinLen[i]
            i += 1
        return longestCommonPref
        
        