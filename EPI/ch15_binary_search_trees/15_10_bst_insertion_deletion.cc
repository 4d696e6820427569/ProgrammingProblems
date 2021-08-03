/**
 * EPI Chapter 15 Binary Search Trees
 *
 * A BST is a dynamic data structure -- in particular, if implemented
 * carefully, key insertion and deletion can be made very fast.
 *
 * Design efficient functions for inserting and removing keys in a BST.
 * Assume that all elements in the BST are unique, and that your insertion
 * method must preserve this property.
 *
 * Hint: Deleting leaves is easy. Pay attention to the children of internal
 * nodes when you delete it.
 */

#include <cstdio>
#include <memory>
#include <cassert>
#include <limits>
#include <vector>
#include <algorithm>

#include "../data_structures/binary_tree.hpp"

using std::make_shared;
using std::shared_ptr;
using std::numeric_limits;
using std::vector;
using std::max;

using data_structures::BinaryTreeNode;
using data_structures::BinarySearchTree;

using pBSTNode = std::shared_ptr<BinaryTreeNode<int>>;

void PrintVect(const vector<int>& v)
{
    for (const auto& e : v)
        printf("%d ", e);
    printf("\n");
}

int main()
{
    BinarySearchTree<int> test_tree1;
    test_tree1.Insert(19);
    test_tree1.Insert(7);
    test_tree1.Insert(43);
    test_tree1.Insert(3);
    test_tree1.Insert(11);
    test_tree1.Insert(23);
    test_tree1.Insert(47);
    test_tree1.Insert(2);
    test_tree1.Insert(5);
    test_tree1.Insert(17);
    test_tree1.Insert(37);
    test_tree1.Insert(53);
    test_tree1.Insert(13);
    test_tree1.Insert(29);
    test_tree1.Insert(41);
    test_tree1.Insert(31);

    vector<int> tree1_inorder{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    vector<int> tree1_inorder_res;
    vector<int> tree1_preorder_res;
    vector<int> tree1_postorder_res;
    test_tree1.Inorder(tree1_inorder_res);
    test_tree1.Preorder(tree1_preorder_res);
    test_tree1.Postorder(tree1_postorder_res);
    printf("Inorder: ");
    PrintVect(tree1_inorder_res);
    printf("Preorder: ");
    PrintVect(tree1_preorder_res);
    printf("Postorder: ");
    PrintVect(tree1_postorder_res);

    return 0;
}
