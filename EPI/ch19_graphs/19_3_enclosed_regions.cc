/**
 * EPI Chapter 19 Graphs
 *
 * 19.3 Compute enclosed regions.
 *
 * Let A be a 2D array whose entries are either W or B. Write a program that
 * takes A and replaces all Ws that cannot reach the boundary with a B.
 *
 * Hint: It's easier to compute the complement of the desired result.
 */

/**
 * Idea: For all white cells that are boundaries, do DFS and mark them as a
 * different color, say Green. And then for all white cells that are enclosed,
 * mark them as Black. Now, for all cells that are Green, mark them as White.
 *
 * Time complexity: O(nm)
 * Space complexity: O(nm)
 */

#include <vector>
#include <array>

using std::vector;
using std::array;

enum class Color
{
    BLACK, WHITE, GREEN
};

void PrintMaze(const vector<vector<Color>>& maze)
{
    int n = static_cast<int>(maze.size());
    int m = static_cast<int>(maze[0].size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            switch(maze[i][j]) {
                case Color::BLACK:
                    printf("B");
                    break;
                case Color::WHITE:
                    printf("W");
                    break;
                case Color::GREEN:
                    printf("G");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

const array<array<int, 2>, 4> kMoves{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

bool MoveAble(const vector<vector<Color>>& A, int x, int y, Color visit_color, Color avoid_color)
{
    int n = static_cast<int>(A.size());
    int m = static_cast<int>(A[0].size());
    if (x < 0 || x >= n || y < 0 || y >= m || (A[x][y] == visit_color || A[x][y] == avoid_color))
        return false;
    return true;
}

void DFS(vector<vector<Color>>& A, int x, int y, Color cur_color, Color visit_color)
{
    if (MoveAble(A, x, y, visit_color, Color::BLACK)) {
        A[x][y] = visit_color;
        for (const auto& move : kMoves) {
            DFS(A, x + move[0], y + move[1], cur_color, visit_color);
        }
    }
}

void ComputeEnclosedRegion(vector<vector<Color>>& A)
{
    int n = static_cast<int>(A.size());
    int m = static_cast<int>(A[0].size());

    // Mark components that are at boundaries as Green.
    for (int i = 0; i < m; i++) {
        if (A[0][i] == Color::WHITE)
            DFS(A, 0, i, Color::WHITE, Color::GREEN);

        if (A[n-1][i] == Color::WHITE)
            DFS(A, n-1, i, Color::WHITE, Color::GREEN);
    }

    for (int i = 0; i < n; i++) {
        if (A[i][0] == Color::WHITE)
            DFS(A, i, 0, Color::WHITE, Color::GREEN);

        if (A[i][m-1] == Color::WHITE)
            DFS(A, i, m-1, Color::WHITE, Color::GREEN);
    }

    // Mark all white cells as Black.
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (A[i][j] == Color::WHITE) {
                DFS(A, i, j, Color::WHITE, Color::BLACK);
            }
        }
    }
    
    // Mark all green cells as white.
    for (int i = 0; i < m; i++) {
        if (A[0][i] == Color::GREEN)
            DFS(A, 0, i, Color::GREEN, Color::WHITE);

        if (A[n-1][i] == Color::GREEN)
            DFS(A, n-1, i, Color::GREEN, Color::WHITE);
    }

    for (int i = 0; i < n; i++) {
        if (A[i][0] == Color::GREEN)
            DFS(A, i, 0, Color::GREEN, Color::WHITE);

        if (A[i][m-1] == Color::GREEN)
            DFS(A, i, m-1, Color::GREEN, Color::WHITE);
    }
}

int main()
{
    // Test case 1.
    vector<vector<Color>> tc1{
        {Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK},
        {Color::WHITE, Color::BLACK, Color::WHITE, Color::BLACK},
        {Color::BLACK, Color::WHITE, Color::WHITE, Color::BLACK},
        {Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK}
    };

    PrintMaze(tc1);

    ComputeEnclosedRegion(tc1);

    PrintMaze(tc1);


    // Test case 2.
    vector<vector<Color>> tc2{
        {Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK},
        {Color::WHITE, Color::WHITE, Color::WHITE, Color::BLACK, Color::BLACK},
        {Color::WHITE, Color::BLACK, Color::BLACK, Color::WHITE, Color::BLACK},
        {Color::WHITE, Color::BLACK, Color::WHITE, Color::WHITE, Color::BLACK},
        {Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK}
    };

    PrintMaze(tc2);

    ComputeEnclosedRegion(tc2);

    PrintMaze(tc2);

    return 0;
}
