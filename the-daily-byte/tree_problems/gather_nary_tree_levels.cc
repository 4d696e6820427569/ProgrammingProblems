/**
 * The Daily Byte - 06/29/2021
 *
 * Gather N-ary Tree Levels.
 *
 * Given an n-ary tree, return its level order traversal.
 * Note: an n-ary tree is a tree in which each node has no more than N
 * children.
 */

#include "../data_structures/nary_tree.h"

#include <vector>
#include <memory>
#include <queue>
#include <utility>
#include <cassert>

using data_structures::NTreeNode;

using std::make_shared;
using std::vector;
using std::shared_ptr;
using std::queue;

using std::make_pair;
using std::pair;

using pNTreeNode = shared_ptr<NTreeNode<int>>;

vector<vector<int>> nary_tree_levels(const pNTreeNode& root)
{
    vector<vector<int>> nary_levels;

    queue< pair <pNTreeNode, int> > q;

    q.emplace(make_pair(root, 0));

    pair<pNTreeNode, int> cur_pair;

    while (!q.empty()) {
        cur_pair = q.front();
        q.pop();

        pNTreeNode cur_node = cur_pair.first;
        int cur_level = cur_pair.second;

        if (cur_level >= static_cast<int>(nary_levels.size())) {
            vector<int> new_level {cur_node->data_};
            nary_levels.emplace_back(new_level);
        } else {
            nary_levels[cur_level].emplace_back(cur_node->data_);
        }

        for (const auto& child : cur_node->children_) {
            q.emplace(make_pair(child, cur_level + 1));
        }
    }

    return nary_levels;
}

int main()
{
    // Test case 1.
    pNTreeNode tc1_root = make_shared<NTreeNode<int>>(NTreeNode<int>(8));
    vector<pNTreeNode> tc1_children_level1 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(2)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(3)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(29))
    };
    tc1_root->children_ = tc1_children_level1;

    vector<vector<int>> tc1_res { {8}, {2, 3, 29} };
    assert(nary_tree_levels(tc1_root) == tc1_res);


    // Test case 2.
    pNTreeNode tc2_root = make_shared<NTreeNode<int>>(NTreeNode<int>(2));
    vector<pNTreeNode> tc2_children_level1 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(1)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(6)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(9))
    };

    tc2_root->children_ = tc2_children_level1;

    vector<pNTreeNode> tc2_children_level2_1 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(8))
    };

    vector<pNTreeNode> tc2_children_level2_2 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(2))
    };

    vector<pNTreeNode> tc2_children_level2_3 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(2))
    };

    tc2_children_level1[0]->children_ = tc2_children_level2_1;
    tc2_children_level1[1]->children_ = tc2_children_level2_2;
    tc2_children_level1[2]->children_ = tc2_children_level2_3;

    vector<pNTreeNode> tc2_children_level3 {
        make_shared<NTreeNode<int>>(NTreeNode<int>(19)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(12)),
        make_shared<NTreeNode<int>>(NTreeNode<int>(90))
    };

    tc2_children_level2_2[0]->children_ = tc2_children_level3;

    vector<vector<int>> tc2_res { {2}, {1, 6, 9}, {8, 2, 2}, {19, 12, 90} }; 
    assert(nary_tree_levels(tc2_root) == tc2_res);

    return 0;
}
