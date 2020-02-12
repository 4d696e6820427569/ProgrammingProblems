class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        revWords = []
        for word in words:
            revWords.append(word[::-1])
        
        
        return " ".join(revWords)