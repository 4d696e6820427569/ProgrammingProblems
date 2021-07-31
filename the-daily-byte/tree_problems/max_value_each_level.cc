/**
 * The Daily Byte - Max value in each level
 *
 * 06/25/2021
 *
 * Given a binary tree, return the largest value in each of its levels.
 */

#include "../data_structures/bst_node.h"

#include <vector>
#include <queue>
#include <cassert>
#include <memory>
#include <utility>

using std::vector;
using std::queue;
using std::make_shared;
using std::shared_ptr;
using std::pair;
using std::make_pair;

using data_structures::BSTNode;
using pBSTNode = shared_ptr<BSTNode<int>>;

void print_vect(const vector<int>& v)
{
    printf("[");
    for (const auto& e : v) {
        printf("%d, ", e);
    }
    printf("]\n");
}

vector<int> max_value_each_level(pBSTNode& tree)
{
    vector<int> max_values;
    queue< pair <pBSTNode, int> > q;

    q.push(make_pair(tree, 0));
   
    pair< pBSTNode, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        pBSTNode cur_node = cur.first;
        int cur_level = cur.second;

        if (cur_level >= static_cast<int>(max_values.size())) {
            max_values.emplace_back(cur_node->data_);
        } else if (max_values[cur_level] < cur_node->data_) {
            max_values[cur_level] = cur_node->data_;
        }

        if (cur_node->left_ != nullptr) {
            q.push(make_pair(cur_node->left_, cur_level+1));
        }

        if (cur_node->right_ != nullptr) {
            q.push(make_pair(cur_node->right_, cur_level+1));
        }

    }

    print_vect(max_values);
    return max_values;
}

int main()
{
    // Test case 1:
    pBSTNode tc1_root   (new BSTNode<int>);
    pBSTNode tc1_l      (new BSTNode<int>);
    pBSTNode tc1_r      (new BSTNode<int>);
    pBSTNode tc1_rr     (new BSTNode<int>);

    tc1_root->data_     = 2;
    tc1_l->data_        = 10;
    tc1_r->data_        = 15;
    tc1_rr->data_       = 20;

    tc1_root->left_     = tc1_l;
    tc1_root->right_    = tc1_r;
    tc1_r->right_       = tc1_rr;

    vector<int> tc1_res{2, 15, 20};
    assert (tc1_res == max_value_each_level(tc1_root));

    // Test case 2:

    pBSTNode tc2_root   (new BSTNode<int>);
    pBSTNode tc2_l      (new BSTNode<int>);
    pBSTNode tc2_r      (new BSTNode<int>);
    pBSTNode tc2_ll     (new BSTNode<int>);
    pBSTNode tc2_lr     (new BSTNode<int>);
    pBSTNode tc2_rr     (new BSTNode<int>);

    tc2_root->data_     = 1;
    tc2_l->data_        = 5;
    tc2_r->data_        = 6;
    tc2_ll->data_       = 5;
    tc2_lr->data_       = 3;
    tc2_rr->data_       = 7;

    tc2_root->left_     = tc2_l;
    tc2_root->right_    = tc2_r;
    tc2_r->right_       = tc2_rr;
    tc2_l->left_        = tc2_ll;
    tc2_l->right_       = tc2_lr;

    vector<int> tc2_res{1, 6, 7};
    assert (tc2_res == max_value_each_level(tc2_root));

    // Test case 4

    pBSTNode tc4_root   (new BSTNode<int>);
    pBSTNode tc4_l      (new BSTNode<int>);
    pBSTNode tc4_r      (new BSTNode<int>);
    pBSTNode tc4_ll     (new BSTNode<int>);
    pBSTNode tc4_lr     (new BSTNode<int>);
    pBSTNode tc4_rl     (new BSTNode<int>);
    pBSTNode tc4_rr     (new BSTNode<int>);

    
    tc4_root->data_     = 1;
    tc4_l->data_        = 2;
    tc4_r->data_        = 3;
    tc4_ll->data_       = 4;
    tc4_lr->data_       = 5;
    tc4_rl->data_       = 6;
    tc4_rr->data_       = 7;

    tc4_root->left_     = tc4_l;
    tc4_root->right_    = tc4_r;
    tc4_l->left_        = tc4_ll;
    tc4_l->right_       = tc4_lr;
    tc4_r->left_        = tc4_rl;
    tc4_r->right_       = tc4_rr;

    vector<int> tc4_res{1, 3, 7};
    assert(tc4_res == max_value_each_level(tc4_root));

    return 0;
}
