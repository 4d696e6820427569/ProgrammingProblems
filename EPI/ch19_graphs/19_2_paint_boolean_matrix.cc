/**
 * EPI Chapter 19 Graphs
 *
 * 19.2 Paint a boolean matrix
 *
 * Let A be a Boolean 2D array encoding a black-and-white image. The entry
 * A(a, b) can be viewed as encoding the color at entry (a, b). Call 2 entries
 * adjacent if one is to the left, right, above or below the other. Note that
 * the definition implies that an entry can be adjacent to at most 4 other
 * entries, and that adjacency is symmetric, i.e., if e0 is adjacent to entry
 * e1, then e1 is adjacent to e0.
 *
 * Define a path from entry e0 to entry e1 to be a sequence of adjacent
 * entries, starting at e0, ending at e1, with successive entries being
 * adjacent. Define the region associated with a point(i, j) to be all points
 * (i', j') such that there exists a path from (i, j) to (i', j') in which all
 * entries are the same color. In particular, this implies (i, j) and (i', j')
 * must be the same color.
 *
 * Implement a routine that takes an n x m boolean array A together with an
 * entry (x, y) and flips the color of the region associated with (x, y).
 *
 * Hint: Solve this conceptually, then think about optimization.
 */

#include <vector>
#include <queue>
#include <deque>
#include <cstdio>

using std::vector;
using std::queue;
using std::deque;

const int kDirection[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void PrintMaze(const vector<deque<bool>>& maze, const int& x, const int& y)
{
    int n = static_cast<int>(maze.size());
    int m = static_cast<int>(maze[0].size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == x && j == y) {
                printf("X");
            } else if (maze[i][j]) {
                printf("W");
            } else {
                printf("B");
            }
        }
        printf("\n");
    }
    printf("\n");
}
/**
 * Idea: Perform BFS on (x, y), flipping all point that to different color
 *
 * Time complexity: O(n * m) because there are n * m vertices. There's no edges
 *  because the maximum number of edges can only be 4.
 *
 * Space complexity: O(n * m)
 */
void FlipColor(vector<deque<bool>>& A, int x, int y)
{
    int n = static_cast<int>(A.size());
    int m = static_cast<int>(A[0].size());

    queue<int> q;

    // Flip the starting point's color.
    A[x][y] = !A[x][y];

    q.emplace(x * n + y);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        int cur_x = f / n;
        int cur_y = f % n;

        for (int i = 0; i < 4; i++) {
            int new_x = cur_x + kDirection[i][0];
            int new_y = cur_y + kDirection[i][1];

            if (new_x < 0 || new_x >= n || new_y < 0 || new_x >= m ||
                    A[new_x][new_y] == A[x][y]) {
                continue;
            }

            // Flip its color or mark it as visited.
            A[new_x][new_y] = !A[new_x][new_y];
            q.emplace(new_x * n + new_y);
        }
        
    }

}

int main()
{
    vector<deque<bool>> tc(10, deque<bool>(10, true));

    tc[0][0] = false;
    tc[0][2] = false;
    tc[0][6] = false;
    tc[0][7] = false;
    tc[0][8] = false;
    tc[0][9] = false;

    tc[1][2] = false;
    tc[1][5] = false;
    tc[1][8] = false;
    tc[1][9] = false;

    tc[2][0] = false;
    tc[2][1] = false;
    tc[2][2] = false;
    tc[2][5] = false;
    tc[2][6] = false;
    tc[2][8] = false;
    tc[2][9] = false;

    tc[3][1] = false;
    tc[3][3] = false;
    tc[3][4] = false;
    tc[3][5] = false;
    tc[3][6] = false;
    tc[3][8] = false;

    tc[4][0] = false;
    tc[4][2] = false;
    tc[4][7] = false;

    tc[5][0] = false;
    tc[5][2] = false;
    tc[5][5] = false;
    tc[5][7] = false;
    tc[5][8] = false;
    tc[5][9] = false;

    tc[6][4] = false;
    tc[6][6] = false;
    tc[6][9] = false;

    tc[7][0] = false;
    tc[7][2] = false;
    tc[7][4] = false;
    tc[7][6] = false;

    tc[8][0] = false;
    tc[8][2] = false;
    tc[8][3] = false;
    tc[8][7] = false;
    tc[8][8] = false;
    tc[8][9] = false;

    tc[9][7] = false;
    tc[9][8] = false;

    int start_x = 5;
    int start_y = 4;
    PrintMaze(tc, start_x, start_y);

    FlipColor(tc, start_x, start_y);

    start_x = 3;
    start_y = 6;
    PrintMaze(tc, start_x, start_y);

    FlipColor(tc, start_x, start_y);

    PrintMaze(tc, -1, -1);

    return 0;
}
