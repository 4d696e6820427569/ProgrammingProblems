/**
 * The Daily Byte - 06/27/2021
 *
 * Given a binary tree, returns all of its levels in a bottom-up fashion
 * (i. e. last level towards the root).
 */

#include "../data_structures/bst_node.h"

#include <cassert>
#include <cstdio>
#include <memory>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::make_shared;
using std::shared_ptr;

using data_structures::BSTNode;

using pBSTNode = shared_ptr<BSTNode<int>>;

void print_matrix(const vector<vector<int>>& m )
{
    printf("[");
    for (const auto& v : m) {
        printf("[");
        for (const auto& e : v) {
            printf("%d ,", e);
        }
        printf("]");
    }
    printf("]");
}


/*
 * Do level order tree traversal and reverse the levels array.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
vector< vector<int> > bottoms_up_level_order(pBSTNode tree)
{
    vector< vector<int> > result;

    queue< pair<pBSTNode, int> > q;

    q.emplace(make_pair(tree, 0) );

    pair< pBSTNode, int > cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        pBSTNode cur_node = cur.first;
        int cur_level = cur.second;

        if (cur_level >= static_cast<int>(result.size())) {
            vector<int> new_level {cur_node->data_};
            result.emplace_back(new_level);
        } else {
            result[cur_level].emplace_back(cur_node->data_);
        }

        if (cur_node->left_ != nullptr) {
            q.emplace(make_pair(cur_node->left_, cur_level + 1));
        }

        if (cur_node->right_ != nullptr) {
            q.emplace(make_pair(cur_node->right_, cur_level + 1));
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    // Test case 1.
    pBSTNode tc1_root       (new BSTNode<int>);
    pBSTNode tc1_l          (new BSTNode<int>);
    pBSTNode tc1_r          (new BSTNode<int>);

    tc1_root->data_         = 2;
    tc1_l->data_            = 1;
    tc1_r->data_            = 2;

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;

    vector< vector<int> > tc1_res{ {1, 2}, {2} };
    assert(tc1_res == bottoms_up_level_order(tc1_root));

    // Test case 2.
    pBSTNode tc2_root       (new BSTNode<int>);
    pBSTNode tc2_r          (new BSTNode<int>);
    pBSTNode tc2_l          (new BSTNode<int>);
    pBSTNode tc2_ll         (new BSTNode<int>);
    pBSTNode tc2_lr         (new BSTNode<int>);

    tc2_root->data_         = 7;
    tc2_r->data_            = 2;
    tc2_l->data_            = 6;
    tc2_ll->data_           = 3;
    tc2_lr->data_           = 3;

    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;
    tc2_l->left_            = tc2_ll;
    tc2_l->right_           = tc2_lr;

    vector< vector<int> > tc2_res { {3, 3}, {6, 2}, {7} };
    assert( tc2_res == bottoms_up_level_order(tc2_root) );

    return 0;
}
