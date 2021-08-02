/**
 * EPI Chapter 15 Binary Search Trees
 *
 * 15.7 Enumerate numbers of the form a + b sqrt(2)
 *
 * Numbers of the form a + b sqrt(q), where a and b are nonnegative intergers,
 * and q is an integer which is not the square of another integer, have special
 * properties, e.g., they are closed unrder addition and multiplication. Some
 * of the first few numbers of this form are given
 *
 * Design an algorithm for efficintly computing the k smallest numbers of the
 * form a + b sqrt(2) for nonnegative integers a and b.
 */

#include <cstdio>
#include <memory>
#include <cassert>
#include <limits>
#include <vector>

#include "../data_structures/binary_tree.hpp"

using std::make_shared;
using std::shared_ptr;
using std::numeric_limits;
using std::vector;

using data_structures::BinaryTreeNode;

using pBSTNode = std::shared_ptr<BinaryTreeNode<int>>;

void PrintVect(const vector<int>& v)
{
    for (const auto& e : v)
        printf("%d ", e);
    printf("\n");
}


int main()
{
    return 0;
}
