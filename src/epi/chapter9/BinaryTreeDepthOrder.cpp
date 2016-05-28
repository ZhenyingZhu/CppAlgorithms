#include "BinaryTreeDepthOrder.hpp"

#include <memory>
#include <queue>
#include <vector>
#include <stdexcept>
#include <iostream>

using std::queue;
using std::unique_ptr;
using std::vector;
using std::string;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter9 {
    vector<vector<int>> BinaryTreeDepthOrder::binaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>> &tree) {
        queue<BinaryTreeNode<int>*> processingNodes;
        processingNodes.push(tree.get());
        size_t levelSize = processingNodes.size();

        vector<vector<int>> res;
        vector<int> curLevel;

        while (!processingNodes.empty()) {
        }

        return res;
    }

    bool BinaryTreeDepthOrder::test() {
        return true;
    }

  } // chapter9
} // epi
