class Solution:
    def reverseVowels(self, s: str) -> str:
        sToCharArray = list(s)
        vowels = ['a', 'e', 'i', 'o', 'u']
        i = 0
        j = len(sToCharArray) - 1
        while(i < j):
            while(s[i].lower() not in vowels and i < j):
                i += 1
            while(s[j].lower() not in vowels and j > i):
                j -= 1

            temp = sToCharArray[i]
            sToCharArray[i] = sToCharArray[j]
            sToCharArray[j] = temp

            i += 1
            j -= 1


        return ''.join(sToCharArray)
