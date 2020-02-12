class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        solList = []
        for i in range(1,n+1):
            if (i % 15 == 0):
                solList.append("FizzBuzz")
            elif (i % 5 == 0):
                solList.append("Buzz")
            elif (i % 3 == 0):
                solList.append("Fizz")
            else:
                solList.append(str(i))
        return solList
            
        