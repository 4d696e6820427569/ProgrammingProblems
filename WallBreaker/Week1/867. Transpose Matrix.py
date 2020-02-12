class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        new_col = len(A)
        new_row = len(A[0])
        A_T = []
        for i in range(new_row):
            cur_row = []
            for j in range(new_col):
                cur_row.append(A[j][i])
            A_T.append(cur_row)
            
        return A_T
        