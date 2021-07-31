/**
 * Given a binary tree, return its column order traversal from top to bottom
 * and from left to right. Note: if 2 nodes are in the same row and column,
 * order them from left to right.
 *
 * For each node at position (row, col), its left and right children will be
 * at positions (row + 1, col - 1) and (row + 1, col + 1), respectively.
 *
 * The root of the tree is at (0, 0).
 */

#include <vector>
#include <map>
#include <queue>
#include <memory>
#include <cassert>
#include <utility>
#include <algorithm>

#include "../data_structures/bst_node.h"

using std::vector;
using std::map;
using std::shared_ptr;
using std::make_shared;
using std::pair;
using std::make_pair;
using std::queue;

using data_structures::BSTNode;
using pBSTNode = shared_ptr<BSTNode<int>>;

void print_matrix(const vector<vector<int>>& m)
{
    printf("[");
    for (const auto& v : m) {
        printf("[");
        for (const auto& e : v) {
            printf("%d, ", e);
        }
        printf("], ");
    }
    printf("]\n");
}

/**
 * For each node at position (row, col), its left and right children will be at
 * positions (row + 1, col - 1), and (row + 1, col + 1). The root of the tree is
 * at (0, 0). We can do BFS on the tree for which we assign the coordinates to
 * our nodes with respect to their parents.
 */
vector<vector<int>> gather_columns(const pBSTNode& root)
{
    vector<vector<int>> columns;

    queue<pair<pBSTNode, pair<int, int>>> q;

    q.emplace(make_pair(root, make_pair(0, 0)));

    map<int, vector<pair<int, int>>> m;

    pair<pBSTNode, pair<int, int>> cur_pair;
    while (!q.empty()) {
        cur_pair = q.front();
        q.pop();

        pBSTNode cur_node = cur_pair.first;
        pair<int, int> cur_coord = cur_pair.second;

        // Do something to add the cur_node to a map/list.
        if (m.count(cur_coord.second) == 0) {
            m[cur_coord.second] = {make_pair(cur_node->data_, cur_coord.first)};
        } else {
            m[cur_coord.second].emplace_back(make_pair(cur_node->data_, cur_coord.first));
        }

        // Push the children onto the queue.
        if (cur_node->left_ !=  nullptr) {
            int left_child_row = cur_coord.first + 1;
            int left_child_col = cur_coord.second - 1;
            q.emplace(make_pair(cur_node->left_, make_pair(left_child_row,
                            left_child_col)));
        }

        if (cur_node->right_ != nullptr) {
            int right_child_row = cur_coord.first + 1;
            int right_child_col = cur_coord.second + 1;
            q.emplace(make_pair(cur_node->right_, make_pair(right_child_row,
                            right_child_col)));
        }
    }

    size_t idx = 0;
    for (auto& p : m) {
        sort(p.second.begin(), p.second.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.second == p2.second)
                return p1.first < p2.first;
            else
                return p1.second < p2.second;
        });

        columns.emplace_back(vector<int>());
        for (size_t i = 0; i < p.second.size(); i++) {
            columns[idx].emplace_back(p.second[i].first);
        }
        idx++;
    }
    
    return columns;
}

int main()
{
    // Test case 1.
    pBSTNode tc1_root       (new BSTNode<int>);
    pBSTNode tc1_l          (new BSTNode<int>);
    pBSTNode tc1_r          (new BSTNode<int>);
    pBSTNode tc1_rl         (new BSTNode<int>);
    pBSTNode tc1_rr         (new BSTNode<int>);

    tc1_root->data_         = 8;
    tc1_l->data_            = 2;
    tc1_r->data_            = 29;
    tc1_rl->data_           = 3;
    tc1_rr->data_           = 9;

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;
    tc1_r->left_            = tc1_rl;
    tc1_r->right_           = tc1_rr;

    vector<vector<int>> tc1_res {{2}, {8, 3}, {29}, {9}};
    assert(gather_columns(tc1_root) == tc1_res);

    // Test case 2.
    pBSTNode tc2_root       (new BSTNode<int>);  
    pBSTNode tc2_l          (new BSTNode<int>); 
    pBSTNode tc2_r          (new BSTNode<int>); 
    pBSTNode tc2_ll         (new BSTNode<int>); 
    pBSTNode tc2_lr         (new BSTNode<int>); 
    pBSTNode tc2_rl         (new BSTNode<int>); 
    pBSTNode tc2_rr         (new BSTNode<int>);

    tc2_root->data_         = 100;
    tc2_l->data_            = 53;
    tc2_r->data_            = 78;
    tc2_ll->data_           = 32;
    tc2_lr->data_           = 3;
    tc2_rl->data_           = 9;
    tc2_rr->data_           = 20;

    tc2_root->left_         = tc2_l;
    tc2_root->right_        = tc2_r;
    tc2_l->left_            = tc2_ll;
    tc2_l->right_           = tc2_lr;
    tc2_r->left_            = tc2_rl;
    tc2_r->right_           = tc2_rr;

    vector<vector<int>> tc2_res {{32}, {53}, {100, 3, 9}, {78}, {20}};
    assert(gather_columns(tc2_root) == tc2_res);

    return 0;
}
