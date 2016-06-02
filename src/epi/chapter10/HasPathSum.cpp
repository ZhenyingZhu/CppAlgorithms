#include "HasPathSum.hpp"

#include <memory>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <vector>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using myutils::BinaryTreeNode;
using std::abs;
using std::max;
using std::swap;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    bool HasPathSum::hasPathSumHelper(const unique_ptr<BinaryTreeNode<int>> &node, int partialPathSum, int targetSum) {
        if (!node)
            return 0;

        partialPathSum += node.get()->data;

        if (!node.get()->left && !node.get()->right)
            return partialPathSum == targetSum; // Leaf

        bool left = hasPathSumHelper(node.get()->left, partialPathSum, targetSum);
        bool right = hasPathSumHelper(node.get()->right, partialPathSum, targetSum);

        return left || right;
    }

    bool HasPathSum::hasPathSum(const unique_ptr<BinaryTreeNode<int>> &tree, int targetSum) {
        return hasPathSumHelper(tree, 0, targetSum);
    }

    bool HasPathSum::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, 256, 256, 0, 256, 256,
                561, 256, 3, 17, 256, 256, 256,
                6, 2, 256, 1, 401, 256, 641, 256, 256, 257, 256, 256,
                271, 256, 28
        };
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, new size_t(0));

        bool res = hasPathSum(root1, 591);

        if (!res) {
            cout << "should exist" << endl;
            cout << "but not exist" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
