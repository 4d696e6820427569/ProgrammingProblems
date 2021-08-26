/**
 * The Daily Byte
 *
 * Given a reference to the root of a binary tree, return a list containing
 * the average value in each level of the tree.
 */

#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <memory>
#include <utility>
#include <iostream>

#include "../data_structures/bst_node.h"

using std::vector;
using std::queue;
using std::make_shared;
using std::shared_ptr;
using std::pair;

using data_structures::BSTNode;

typedef shared_ptr<BSTNode<int>> pBSTNode;

template <typename T>
void PrintVect(const vector<T>& arr)
{
    for (const auto& e : arr)
        std::cout << e << " ";
    std::cout << "\n";
}

template <typename T>
void PrintMatrix(const vector<T>& m)
{
    for (const auto& v : m)
        PrintVect(v);
}

/**
 * Idea: Do level order traversal (BFS). Gather all nodes at the same
 * level. And calculate the average for each level.
 *
 * Time complexity: O(n) need to traversal all nodes. Linear because
 *  tree has fixed number of subtrees.
 * Space complexity: O(n) for array and queue to store all nodes.
 */
vector<double> Average(const pBSTNode& root)
{
    vector<double> avgs;
    vector<vector<double>> level_order;

    queue<pair<pBSTNode, int>> q;
    q.emplace(make_pair(root, 0));

    while (!q.empty()) {
        pBSTNode cur_node = q.front().first;
        int cur_level = q.front().second;
        q.pop();
        if (level_order.empty() || cur_level >= level_order.size()) {
            level_order.emplace_back(vector<double>{static_cast<double>(cur_node->data_)});
        } else {
            level_order[cur_level].emplace_back(static_cast<double>(cur_node->data_));
        }

        if (cur_node->left_ != nullptr)
            q.emplace(make_pair(cur_node->left_, cur_level+1));
        if (cur_node->right_ != nullptr)
            q.emplace(make_pair(cur_node->right_, cur_level+1));
    }

    for (const auto& v : level_order) {
        double avg = 0;
        int count = 0;
        for (const auto& e : v) {
            avg += e;
            count++;
        }

        avgs.emplace_back(avg/count);
    }

    return avgs;
}

int main()
{
    pBSTNode tc1_root   (make_shared<BSTNode<int>>(1));
    pBSTNode tc1_l      (make_shared<BSTNode<int>>(6));
    pBSTNode tc1_r      (make_shared<BSTNode<int>>(8));
    pBSTNode tc1_ll     (make_shared<BSTNode<int>>(1));
    pBSTNode tc1_lr     (make_shared<BSTNode<int>>(5));

    tc1_root->left_     = tc1_l;
    tc1_root->right_    = tc1_r;
    tc1_l->left_        = tc1_ll;
    tc1_l->right_       = tc1_lr;

    vector<double> tc1_res{1.0, 7.0, 3.0};
    assert(Average(tc1_root) == tc1_res);
    return 0;
}
