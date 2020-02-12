class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        self.friends = list(range(n))
        
        connectedComponents = dict()
        for i in range(n):
            for j in range(n):
                if i != j and M[i][j] == 1 and self.friends[i] != self.friends[j]:
                    self.union(i, j)
        
        for i in range(n):
            iRoot = self.find(i)
            if iRoot not in connectedComponents:
                connectedComponents[iRoot] = [i]
            else:
                connectedComponents[iRoot].append(i)
                
        return len(connectedComponents.keys())
        
    def find(self,x):
        if self.friends[x] != x:
            self.friends[x] = self.find(self.friends[x])
        return self.friends[x]
    
    def union(self, x, y):
        xRoot = self.find(x)
        yRoot = self.find(y)
        self.friends[xRoot] = yRoot
        