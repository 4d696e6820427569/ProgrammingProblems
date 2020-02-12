class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if (word == ""):
            return False
        else:
            if (ord(word[0]) < ord('a')):
                if (len(word) == 1):
                    return True
                else:
                    if (ord(word[1]) < ord('a')):
                        for i in range(2, len(word), 1):
                            if (ord(word[i]) >= ord('a')):
                                return False
                    else:
                        for i in range(2, len(word), 1):
                            if (ord(word[i]) < ord('a')):
                                return False
                        
            else:
                for i in range(1, len(word),1):
                    if (ord(word[i]) < ord('a')):
                        return False
        return True
        