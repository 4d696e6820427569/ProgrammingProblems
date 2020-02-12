import java.util.*;
class Solution {

    public int numIslands(char[][] grid) {
        // Basically counting the connected components given a graph grid.
        if (grid == null || grid.length == 0) return 0;
        int counter = 0;
        int nr = grid.length, nc = grid[0].length;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    counter++;
                    Queue<Integer> q = new LinkedList<>();
                    q.add(i*nc + j);
                    while (!q.isEmpty()) {
                        int curCoor = q.poll();
                        int x = curCoor / nc, y = curCoor % nc;
                        if (x-1 >= 0 && grid[x-1][y] == '1') {q.add((x-1)*nc + y); grid[x-1][y] = '0';};
                        if (x+1 < nr && grid[x+1][y] == '1') {q.add((x+1)*nc + y); grid[x+1][y] = '0';};
                        if (y-1 >= 0 && grid[x][y-1] == '1') {q.add(x*nc + y-1); grid[x][y-1] = '0';};
                        if (y+1 < nc && grid[x][y+1] == '1') {q.add(x*nc + y+1); grid[x][y+1] = '0';};
                    }
                }
            }
        }
        return counter;
    }

}