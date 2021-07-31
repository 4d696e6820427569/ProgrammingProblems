/**
 * The Daily Byte
 * 07/05/2021
 *
 * Given a binary tree, return whether or not it forms a reflection across its
 * center (i.e. a line drawn straight down starting from the root).
 *
 * Note: A reflection is when an image, flipped across a specified line, forms
 * the same image.
 */

#include <memory>
#include <cassert>
#include <utility>
#include <string>
#include <vector>
#include <queue>

#include "../data_structures/bst_node.h"

using std::make_shared;
using std::shared_ptr;
using std::pair;
using std::make_pair;
using std::string;
using std::queue;
using std::vector;
using std::to_string;

using data_structures::BSTNode;
using pTreeNode = shared_ptr<BSTNode<int>>;

bool vector_is_symmetric(const vector<string>& v)
{
    size_t i = 0, j = v.size() - 1;
    while (i < j)
        if (v[i++] != v[j--]) return false;
    return true;
}

/**
 * Claim: A binary tree is symmetrical if and only if for each level in the left
 * and right subtree, the order of nodes on the left is the reversal of the order
 * of nodes on the right subtree.
 *
 * Level order: [[1], [[2], [2]] , [[4, 5], [5, 4]], [[3, 7, 8, 10], [10, 8, 7, 3]]]
 */
bool is_symmetrical_bfs(const pTreeNode root)
{
    queue< pair<pTreeNode, size_t> > q;
    
    q.emplace(make_pair(root, 0));

    vector<vector<string>> level_order;

    pair<pTreeNode, size_t> cur_pair;

    while(!q.empty()) {
        cur_pair = q.front();
        q.pop();

        pTreeNode cur_node = cur_pair.first;
        size_t cur_level = cur_pair.second;

        if (cur_level >= level_order.size()) {
            vector<string> new_level;
            if (cur_node == nullptr) new_level.emplace_back("*");
            else new_level.emplace_back(to_string(cur_node->data_));
        } else {
            if (cur_node == nullptr)
                level_order[cur_level].emplace_back("*");
            else
                level_order[cur_level].emplace_back(to_string(cur_node->data_));
        }

        if (cur_node != nullptr) {
            q.emplace(make_pair(cur_node->left_, cur_level + 1));
            q.emplace(make_pair(cur_node->right_, cur_level + 1));
        }
    }

    for (const auto& v : level_order) {
        if (!vector_is_symmetric(v)) return false;
    }

    return true;
}

int main()
{
    return 0;
}
