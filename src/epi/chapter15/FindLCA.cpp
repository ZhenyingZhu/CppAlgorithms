#include "FindLCA.hpp"

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BSTNode;
using myutils::BST_INT_NULL;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    BSTNode<int>* FindLCA::findLCA(const unique_ptr<BSTNode<int>> &tree,
                                   const unique_ptr<BSTNode<int>> &a,
                                   const unique_ptr<BSTNode<int>> &b) {
        int low = a.get()->data, high = b.get()->data;
        assert(low != high);
        if (low > high) {
            int tmp = low;
            low = high;
            high = tmp;
        }

        BSTNode<int> *node = tree.get();
        while (node) {
            if (node->data == low || node->data == high
                    || (node->data > low && node->data < high) )
                return node;

            if (node->data < low) {
                node = node->right.get();
            } else {
                node = node->left.get();
            }
        }

        return nullptr;
    }

    bool FindLCA::test() {
        vector<int> preOrder = {19, 7, 3, 2, BST_INT_NULL, BST_INT_NULL, 5, BST_INT_NULL, BST_INT_NULL, 11, BST_INT_NULL,
                17, 13, BST_INT_NULL, BST_INT_NULL, BST_INT_NULL, 43, 23, BST_INT_NULL, 37, 29, BST_INT_NULL, 31, BST_INT_NULL, BST_INT_NULL,
                41, BST_INT_NULL, BST_INT_NULL, 47, BST_INT_NULL, 53, BST_INT_NULL, BST_INT_NULL};

        unique_ptr<BSTNode<int>> tree = createPreOrderIntBST(preOrder, new size_t(0));
        unique_ptr<BSTNode<int>> &c = tree.get()->left.get()->left;
        unique_ptr<BSTNode<int>> &g = tree.get()->left.get()->right.get()->right;

        int ans = 7;

        BSTNode<int> *res = findLCA(tree, c, g);

        if (res->data != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result " << res->data << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
