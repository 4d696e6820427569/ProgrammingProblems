/**
 * EPI Chapter 16 Recursion
 *
 * 16.1 The towers of Hanoi problem.
 *
 * A peg contains rings in sorted order, with the largest ring being the
 * lowest. You are to transfer these rings to another peg, which is initially
 * empty.
 *
 * Write a program which prints a sequence of operations that transfers n rings
 * from one peg to another. You have a third peg, which is initially empty. The
 * only operation you can perform is taking a single ring from the top of one
 * peg and placing it on top of another peg. You must never place a larger ring
 * above a smaller ring.
 *
 * Hint:
 */

#include <vector>
#include <stack>

using std::vector;
using std::stack;

static const int kNumPegs = 3;

void ComputeTowerHanoiSteps(int rings_to_move, 
        vector<stack<int>>& pegs, int from_peg, int to_peg, int use_peg)
{
    if (rings_to_move > 0) {
        ComputeTowerHanoiSteps(rings_to_move-1, pegs,
                from_peg, use_peg, to_peg);
        int moving_ring = pegs[from_peg].top();
        pegs[to_peg].emplace(moving_ring);
        pegs[from_peg].pop();
        printf("Moving ring %d from peg #%d to peg #%d\n", moving_ring, from_peg, to_peg);
        ComputeTowerHanoiSteps(rings_to_move-1, pegs, use_peg, to_peg, from_peg);
    }
}

void ComputeTowerHanoi(int num_rings)
{
    vector<stack<int>> pegs(kNumPegs);

    for (int i = num_rings; i > 0; i--)
        pegs[0].emplace(i);

    ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2);
}

int main()
{
    int tc1_rings = 4;
    ComputeTowerHanoi(tc1_rings);
    return 0;
}
