/**
 * You are given an undirected graph consisting of N vertices, numbered from
 * 1 to N, and M edges. The graph is described by 2 arrays, A and B, both of
 * length M. A pair (A[K], B[K]), for K from 0 to M-1 describes an edge between
 * vertex A[K] and vertex B[K].
 *
 * Your task is to assign all values from the range [1..N] to the vertices of
 * the graph, giving one number to each of the vertices. Do it in such a way
 * that the sum over all edges of the values at the edges' endpoints is
 * maximal.
 *
 * For example, given N = 5, A = [2, 2, 1, 2] = [1, 3, 4, 4], the graph has 4
 * edges (2, 1), (2, 3), (1, 4), (2, 4). In order to obtain the maximum sum of
 * weights, you can assign the following values to the vertices: 3, 5, 2, 4, 1
 * (to vertices 1, 2, 3, 4, 5 respectively).
 *
 * This way we obtain the sum of values at all edges' endpoints equal to
 * 7 + 8 + 7 + 9 = 31:
 *
 * edge (2, 3): 7 = 5 (vertex 2) + 2 (vertex 3)
 * edge (2, 1): 8 = 5 (vertex 2) + 3 (vertex 1)
 * edge (1, 4): 7 = 3 (vertex 1) + 4 (vertex 4)
 * edge (2, 4): 9 = 5 (vertex 2) + 4 (vertex 4)
 *
 * Notice that the value assigned to vertex 5 did not have any effect on the
 * final result as it is not an endpoint of any edge.
 *
 * Write a function that given, a positive integer N and 2 arrays A, B or M
 * positive integers, returns the maximum possible sum of values of the edges'
 * endpoints.
 *
 * Examples:
 *
 * 1. Given N = 5, A = [2, 2, 1, 2], B = [1, 3, 4, 4], the function should
 * return 31, as explained above.
 *
 * 2. Given N = 3, A = [1], B = [3] function should return 5. The graph
 * contains only 1 edge (1, 3). We can assign the following values to the
 * vertices: 2, 1, 3.
 *
 * The sum of values at the edges' endpoints is (4 + 3) + (2 + 1) = 10.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [2..100,000];
 * M is an integer within the range [1..100,000];
 * All elements of arrays A and B are integers within the range [1..N];
 * There are no self-loops (edges with A[K] = B[K]) in the graph;
 * There are no multiple edges between the same vertices;
 * N * M <= 1,000,000,000
 */

#include <vector>

using std::vector;

int MaximumPossibleSumValues(int N, vector<int>& A, vector<int>& B)
{
    return 0;
}

int main()
{
    return 0;
}
