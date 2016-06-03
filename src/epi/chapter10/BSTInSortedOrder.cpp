#include "BSTInSortedOrder.hpp"

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
    struct BSTInSortedOrder::Status {
        BinaryTreeNode<int> *nodePtr;
        bool leftTraversed;
    };

    vector<int> BSTInSortedOrder::inSortedOrder(const unique_ptr<BinaryTreeNode<int>> &tree) {
        vector<int> inOrder;
        if (!tree)
            return inOrder;

        stack<Status> pendingNodes;
        pendingNodes.push({tree.get(), false});

        while (!pendingNodes.empty()) {
            Status cur = pendingNodes.top();
            pendingNodes.pop();

            if (cur.leftTraversed) {
                inOrder.push_back(cur.nodePtr->data);
            } else {
                cur.leftTraversed = true;
                if (cur.nodePtr->right)
                    pendingNodes.push({cur.nodePtr->right.get(), false});

                pendingNodes.push(cur);

                if (cur.nodePtr->left)
                    pendingNodes.push({cur.nodePtr->left.get(), false});
            }
        }

        return inOrder;
    }

    bool BSTInSortedOrder::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, 256, 256, 0, 256, 256,
                561, 256, 3, 17, 256, 256, 256,
                6, 2, 256, 1, 401, 256, 641, 256, 256, 257, 256, 256,
                271, 256, 28
        };
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, new size_t(0));

        vector<int> res = inSortedOrder(root1);
        vector<int> ans = {28, 271, 0, 6, 561, 17, 3, 314, 2, 401, 641, 1, 257, 6, 271, 28};

        if (res != ans) {
            cout << "should be " << vec_to_string(ans) << endl;
            cout << "result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
