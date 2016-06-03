#include "PreorderTraversal.hpp"

#include <memory>
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::stack;
using myutils::BinaryTreeNode;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    vector<int> PreorderTraversal::preorderTraversal(const unique_ptr<BinaryTreeNode<int>> &tree) {
        vector<int> preOrder;
        if (!tree)
            return preOrder;

        stack<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(tree.get());

        while (!pendingNodes.empty()) {
            auto cur = pendingNodes.top();
            pendingNodes.pop();

            preOrder.push_back(cur->data);

            if (cur->right)
                pendingNodes.push(cur->right.get());

            if (cur->left)
                pendingNodes.push(cur->left.get());
        }

        return preOrder;
    }

    bool PreorderTraversal::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, 256, 256, 0, 256, 256,
                561, 256, 3, 17, 256, 256, 256,
                6, 2, 256, 1, 401, 256, 641, 256, 256, 257, 256, 256,
                271, 256, 28
        };
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, new size_t(0));

        vector<int> res = preorderTraversal(root1);
        vector<int> ans = {314, 6, 271, 28, 0, 561, 3, 17, 6, 2, 1, 401, 641, 257, 271, 28};

        if (res != ans) {
            cout << "should be " << vec_to_string(ans) << endl;
            cout << "result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
