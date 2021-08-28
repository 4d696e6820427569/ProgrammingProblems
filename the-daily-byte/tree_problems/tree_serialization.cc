/**
 * The Daily Byte
 *
 * Given the root to a binary tree, implement serialize(root), which serializes
 * the tree into a string, and deserialize(s), which deserializes the string back
 * into the tree.
 */

#include <vector>
#include <string>
#include <memory>
#include <stack>
#include <iostream>
#include <sstream>
#include <list>

#include "../data_structures/bst_node.h"

using std::string;
using std::vector;
using std::stack;
using std::list;
using std::shared_ptr;
using std::make_shared;
using std::istringstream;
using data_structures::BSTNode;

using pBSTNode = shared_ptr<BSTNode<int>>;

/**
 * Use DFS and use the preorder strategy to traverse the tree.
 */
string Serialize(const pBSTNode& tree)
{
    string res("");

    stack<pBSTNode> s;

    s.emplace(tree);

    while (!s.empty()) {
        pBSTNode cur_node = s.top();
        s.pop();

        if (cur_node == nullptr) {
            res += "None, ";
        } else {
            res += std::to_string(cur_node->data_) + ", ";
            s.emplace(cur_node->right_);
            s.emplace(cur_node->left_);
        }
    }

    return res;
}

pBSTNode DeserializeHelper(list<string>& s)
{
    if (s.empty())
        return nullptr;

    if (s.front() == "None,") {
        s.pop_front();
        return nullptr;
    }

    string in = s.front();
    s.pop_front();
    int value = stoi(in.substr(0, in.size() - 1));
    pBSTNode new_root(make_shared<BSTNode<int>>(value));
    new_root->left_ = DeserializeHelper(s);
    new_root->right_ = DeserializeHelper(s);
    return new_root;
}

pBSTNode Deserialize(const string& s)
{
    istringstream sstr(s);
    string in;
    list<string> s_split;
    while ( sstr >> in ) {
        s_split.emplace_back(in);
    }
    return DeserializeHelper(s_split);
}

int main()
{
    pBSTNode tc1_root   (make_shared<BSTNode<int>>(1));
    pBSTNode tc1_l      (make_shared<BSTNode<int>>(2));
    pBSTNode tc1_r      (make_shared<BSTNode<int>>(5));
    pBSTNode tc1_ll     (make_shared<BSTNode<int>>(3));
    pBSTNode tc1_lr     (make_shared<BSTNode<int>>(4));

    tc1_root->left_         = tc1_l;
    tc1_root->right_        = tc1_r;
    tc1_root->left_->left_  = tc1_ll;
    tc1_root->left_->right_ = tc1_lr;

    std::cout << Serialize(tc1_root) << "\n";
    std::cout << Serialize(Deserialize(Serialize(tc1_root))) << "\n";
    return 0;
}


