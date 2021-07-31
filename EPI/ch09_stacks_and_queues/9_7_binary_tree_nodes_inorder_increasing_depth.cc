/**
 * EPI Chapter 09 Stacks and Queues
 *
 * Compute binary tree nodes in order of increasing depth.
 *
 * Each node in a binary tree has a depth, which is its distance from the root.
 *
 * Given a binary tree, return an array consisting of the keys at the same level.
 *
 * Keys should appear in the order of the corresponding nodes' depths, breaking
 * ties from left to right.
 *
 * Hint: First think about solving this problem with a pair of queues.
 */

#include <vector>
#include <queue>
#include <utility>

#include "../data_structures/binary_tree.hpp"

using std::vector;
using std::queue;

using std::make_unique;
using std::unique_ptr;

using std::make_pair;
using std::pair;

using data_structures::BinaryTreeNode;

void PrintMatrix(const vector<vector<int>>& matrix)
{
    printf("[");
    for (const auto& vector : matrix) {
        printf("[");
        for (const auto& element : vector) {
            printf("%d, ", element);
        }
        printf("], ");
    }
    printf("]\n");
}

vector<vector<int>> BinaryTreeDepthOrderEPI(const unique_ptr<BinaryTreeNode<int>>& root)
{
    vector<vector<int>> result;

    queue<BinaryTreeNode<int>*> curr_depth_nodes({root.get()});

    while (!curr_depth_nodes.empty()) {
        queue<BinaryTreeNode<int>*> next_depth_nodes;
        vector<int> this_level;

        while (!curr_depth_nodes.empty()) {
            auto curr = curr_depth_nodes.front();
            curr_depth_nodes.pop();

            if (curr != nullptr) {
                this_level.emplace_back(curr->data_);

                // Defer the nullptr checks to the null test above.
                next_depth_nodes.emplace(curr->left_.get());
                next_depth_nodes.emplace(curr->right_.get());
            }
        }

        if (!this_level.empty()) {
            result.emplace_back(this_level);
        }

        curr_depth_nodes = next_depth_nodes;
    }

    return result;
}

/**
 * Do BFS. Since each node is enqueued and dequeued exactly once, the time
 * complexity is O(n).
 * The space complexity is O(m), where m is the maximum number of node
 * at any single depth.
 *
 * Time complexity: O(n)
 * Space complexity: O(m)
 */
vector<vector<int>> BinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& root)
{
    using NodeLevel = pair<BinaryTreeNode<int>*, size_t>;

    vector<vector<int>> result;

    queue<NodeLevel> q;

    BinaryTreeNode<int>* tree_ptr = root.get();

    q.emplace(make_pair(tree_ptr, 0));

    NodeLevel cur_pair;
    while (!q.empty()) {
        cur_pair = q.front();
        q.pop();
        
        BinaryTreeNode<int>* cur_node = cur_pair.first;
        size_t cur_level = cur_pair.second;

        if (cur_level >= result.size()) {
            vector<int> new_level {cur_node->data_};
            result.emplace_back(new_level);
        } else {
            result[cur_level].emplace_back(cur_node->data_);
        }

        if (cur_node->left_ != nullptr) {
            q.emplace(make_pair(cur_node->left_.get(), cur_level + 1));
        }

        if (cur_node->right_ != nullptr) {
            q.emplace(make_pair(cur_node->right_.get(), cur_level + 1));
        }
    }

    return result;
}

int main()
{
    unique_ptr<BinaryTreeNode<int>> tc1_root        (make_unique<BinaryTreeNode<int>>(314));
    tc1_root->left_ =                               (make_unique<BinaryTreeNode<int>>(6));
    tc1_root->right_ =                              (make_unique<BinaryTreeNode<int>>(6));
    tc1_root->left_->left_ =                        (make_unique<BinaryTreeNode<int>>(271));
    tc1_root->left_->right_ =                       (make_unique<BinaryTreeNode<int>>(561));
    tc1_root->left_->left_->left_ =                 (make_unique<BinaryTreeNode<int>>(28));
    tc1_root->left_->left_->right_ =                (make_unique<BinaryTreeNode<int>>(0));
    tc1_root->left_->right_->right_ =               (make_unique<BinaryTreeNode<int>>(3));
    tc1_root->left_->right_->right_->left_ =        (make_unique<BinaryTreeNode<int>>(17));

    tc1_root->right_->left_ =                       (make_unique<BinaryTreeNode<int>>(2));
    tc1_root->right_->right_ =                      (make_unique<BinaryTreeNode<int>>(271));
    tc1_root->right_->right_->right_ =              (make_unique<BinaryTreeNode<int>>(28));
    tc1_root->right_->left_->right_ =               (make_unique<BinaryTreeNode<int>>(1));
    tc1_root->right_->left_->right_->left_ =        (make_unique<BinaryTreeNode<int>>(401));
    tc1_root->right_->left_->right_->left_->right_ =(make_unique<BinaryTreeNode<int>>(641));
    tc1_root->right_->left_->right_->right_ =       (make_unique<BinaryTreeNode<int>>(257));

    PrintMatrix(BinaryTreeDepthOrder(tc1_root));

    return 0;
}
