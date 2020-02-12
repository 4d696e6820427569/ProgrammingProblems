class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits) - 1
        if (digits[n] < 9):
            digits[n] += 1
        else:
            digits[n] = 0
            carry = True
            n -= 1
            while(n >= 0 and carry):
                if (digits[n] < 9):
                    digits[n] += 1
                    carry = False
                else:
                    digits[n] = 0
                    carry = True
                n -= 1
                    
            if (carry):
                digits.insert(0, 1)
        return digits
                
                
                
                
            
        