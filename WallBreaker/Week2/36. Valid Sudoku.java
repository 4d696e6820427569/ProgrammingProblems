class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Check row
        for (int i = 0; i < board.length; i++) {
            int[] m = new int[10];
            for (int x = 1; x < 10; x++) m[x] = 1;
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == '.') continue;
                m[board[i][j] - '0']--;
                if (m[board[i][j] - '0'] < 0) return false;
            }
        }

        // Check column
        for (int j = 0; j < board[0].length; j++) {
            int[] m = new int[10];
            for (int x = 1; x < 10; x++) m[x] = 1;
            for (int i = 0; i < board.length; i++) {
                if (board[i][j] == '.') continue;
                m[board[i][j] - '0']--;
                if (m[board[i][j] - '0'] < 0) return false;
            }
        }

        // Check boxes
        for (int i = 0; i < board.length; i += 3) {
            for (int j = 0; j < board[i].length; j += 3) {
                int[] m = new int[10];
                for (int x = 1; x < 10; x++) m[x] = 1;
                for (int k = i; k < i+3; k++) {
                    for (int l = j; l < j+3; l++) {
                        if (board[k][l] == '.') continue;
                        m[board[k][l] - '0']--;
                        if (m[board[k][l] - '0'] < 0) return false;
                    }
                }
            }
        }

        return true;
    }

}
