/**
 * EPI Chapter 10 Binary Trees
 *
 * Given an inorder traversal sequence and a preorder traversal sequence of a
 * binary tree, write a program to reconstruct the tree. Assume each node has a
 * unique key.
 *
 * Variant: Solve the same problem with an inorder traversal sequence and a
 * postorder traversal sequence.
 *
 * Hint: Focus on the root
 */

#include <cstdio>
#include <vector>
#include <cassert>
#include <memory>
#include <unordered_map>
#include <utility>

#include "../data_structures/binary_tree.hpp"

using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::unordered_map;

using data_structures::BinaryTreeNode;
using pTreeNode = shared_ptr<BinaryTreeNode<int>>;

void PrintVect(const vector<int>& v)
{
    for (const auto& e : v)
        printf("%c ", e);
    printf("\n");
}

void PreorderTraversal(pTreeNode tree, vector<int>& preorder)
{
    if (tree != nullptr) {
        preorder.emplace_back(tree->data_);
        PreorderTraversal(tree->left_, preorder);
        PreorderTraversal(tree->right_, preorder);
    }
}

void InorderTraversal(pTreeNode tree, vector<int>& inorder)
{
    if (tree != nullptr) {
        InorderTraversal(tree->left_, inorder);
        inorder.emplace_back(tree->data_);
        InorderTraversal(tree->right_, inorder);
    }
}

void PostorderTraversal(pTreeNode tree, vector<int>& postorder)
{
    if (tree != nullptr) {
        PostorderTraversal(tree->left_, postorder);
        PostorderTraversal(tree->right_, postorder);
        postorder.emplace_back(tree->data_);
    }
}

bool IdenticalTree(pTreeNode tree1, pTreeNode tree2)
{
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    } else if (tree1 != nullptr && tree2 != nullptr) {
        if (tree1->data_ != tree2->data_) return false;
        return IdenticalTree(tree1->left_, tree2->left_) &&
            IdenticalTree(tree1->right_, tree2->right_);
    } else {
        return false;
    }
}


/**
 * Idea: The first node in the preorder array is the root. We can look up
 * the index of this root in the inorder array. Then the first k nodes
 * from the start to the root node in the inorder array are the nodes
 * of the left subtree. The right subtree's on the right of the root node
 * in the inorder sequence.
 *
 * Recursively build our tree from this.
 *
 * Time complexity: O(n + h)
 * Space complexity: O(n)
 */
shared_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorderHelper(
    const vector<int>& preorder, size_t preorder_start, size_t preorder_end,
    const vector<int>& inorder, size_t inorder_start, size_t inorder_end,
    const unordered_map<int, size_t>& inorder_map)
{
    if (preorder_start == preorder_end || inorder_start == inorder_end)
        return nullptr;

    size_t root_inorder_idx = inorder_map.at(preorder[preorder_start]);
    int left_nodes_num = root_inorder_idx - inorder_start;
    return make_shared<BinaryTreeNode<int>>(
            preorder[preorder_start],
            BinaryTreeFromPreorderInorderHelper(
                preorder, preorder_start + 1, preorder_start + 1 + left_nodes_num,
                inorder, inorder_start, inorder_start + left_nodes_num,
                inorder_map),
            BinaryTreeFromPreorderInorderHelper(
                preorder, preorder_start + left_nodes_num + 1, preorder_end,
                inorder, root_inorder_idx + 1, inorder_end,
                inorder_map)
            );
}

shared_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
        const vector<int>& preorder, const vector<int>& inorder)
{
    unordered_map<int, size_t> inorder_map;
    for (size_t i = 0; i < inorder.size(); i++) {
        inorder_map.emplace(inorder[i], i);
    }
    return BinaryTreeFromPreorderInorderHelper(preorder, 0, preorder.size(), 
            inorder, 0, inorder.size(), inorder_map); 
}

/**
 * Use the same strategy for inorder and postorder.
 */
shared_ptr<BinaryTreeNode<int>> BinaryTreeFromPostorderInorderHelper(
        const vector<int>& postorder, int postorder_start, int postorder_end,
        const vector<int>& inorder, int inorder_start, int inorder_end,
        const unordered_map<int, size_t>& inorder_map)
{
    if (postorder_end == postorder_start || inorder_start == inorder_end)
        return nullptr;

    int root_inorder_idx = inorder_map.at(postorder[postorder_end-1]);
    int left_nodes_num = root_inorder_idx - inorder_start;
    return make_shared<BinaryTreeNode<int>>(
            postorder[postorder_end-1],
            BinaryTreeFromPostorderInorderHelper(
                postorder, postorder_start, postorder_start + left_nodes_num,
                inorder, inorder_start, inorder_start + left_nodes_num,
                inorder_map),
            BinaryTreeFromPostorderInorderHelper(
                postorder, postorder_start + left_nodes_num, postorder_end - 1, 
                inorder, root_inorder_idx + 1, inorder_end,
                inorder_map)
            );
}

shared_ptr<BinaryTreeNode<int>> BinaryTreeFromPostorderInorder(
        const vector<int>& postorder, const vector<int>& inorder)
{
    unordered_map<int, size_t> inorder_map;
    for (size_t i = 0; i < inorder.size(); i++) {
        inorder_map.emplace(inorder[i], i);
    }
    return BinaryTreeFromPostorderInorderHelper(postorder, 0, postorder.size(),
            inorder, 0, inorder.size(), inorder_map);
}

int main()
{
    pTreeNode tc1_root          (make_shared<BinaryTreeNode<int>>('H'));
    pTreeNode tc1_l             (make_shared<BinaryTreeNode<int>>('B'));
    pTreeNode tc1_r             (make_shared<BinaryTreeNode<int>>('C'));
    pTreeNode tc1_ll            (make_shared<BinaryTreeNode<int>>('F'));
    pTreeNode tc1_lr            (make_shared<BinaryTreeNode<int>>('E'));
    pTreeNode tc1_lrl           (make_shared<BinaryTreeNode<int>>('A'));
    pTreeNode tc1_rr            (make_shared<BinaryTreeNode<int>>('D'));
    pTreeNode tc1_rrr           (make_shared<BinaryTreeNode<int>>('G'));
    pTreeNode tc1_rrrl          (make_shared<BinaryTreeNode<int>>('I'));

    tc1_root->left_             = tc1_l;
    tc1_root->right_            = tc1_r;
    tc1_l->left_                = tc1_ll;
    tc1_l->right_               = tc1_lr;
    tc1_lr->left_               = tc1_lrl;
    tc1_r->right_               = tc1_rr;
    tc1_rr->right_              = tc1_rrr;
    tc1_rrr->left_              = tc1_rrrl;

    vector<int> tc1_preorder{'H', 'B', 'F', 'E', 'A', 'C', 'D', 'G', 'I'};
    vector<int> tc1_inorder{'F', 'B', 'A', 'E', 'H', 'C', 'D', 'I', 'G'};
    vector<int> tc1_postorder{'F', 'A', 'E', 'B', 'I', 'G', 'D', 'C', 'H'};
    printf("tc1 preorder/inorder/postorder info:\n");
    PrintVect(tc1_preorder);
    PrintVect(tc1_inorder);
    PrintVect(tc1_postorder);
    
    printf("tc1_res preorder/inorder/postorder info:\n");
    pTreeNode tc1_res = BinaryTreeFromPreorderInorder(tc1_preorder, tc1_inorder);
    vector<int> tc1_res_preorder;
    vector<int> tc1_res_inorder;
    vector<int> tc1_res_postorder;
    PreorderTraversal(tc1_res, tc1_res_preorder);
    PrintVect(tc1_res_preorder);
    InorderTraversal(tc1_res, tc1_res_inorder);
    PrintVect(tc1_res_inorder);
    PostorderTraversal(tc1_res, tc1_res_postorder);
    PrintVect(tc1_res_postorder);
    assert(IdenticalTree(tc1_res, tc1_root));

    // Test post and in
    printf("tc1_res_post preorder/inorder/postorder info:\n");
    pTreeNode tc1_res_post = BinaryTreeFromPostorderInorder(tc1_postorder, tc1_inorder);
    vector<int> tc1_res_post_preorder;
    vector<int> tc1_res_post_inorder;
    vector<int> tc1_res_post_postorder;
    PreorderTraversal(tc1_res_post, tc1_res_post_preorder);
    PrintVect(tc1_res_post_preorder);
    InorderTraversal(tc1_res_post, tc1_res_post_inorder);
    PrintVect(tc1_res_post_inorder);
    PostorderTraversal(tc1_res_post, tc1_res_post_postorder);
    PrintVect(tc1_res_post_postorder);
    assert(IdenticalTree(tc1_res_post, tc1_root));

    return 0;
}
