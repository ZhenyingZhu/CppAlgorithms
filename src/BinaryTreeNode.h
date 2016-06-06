#ifndef SRC_BINARYTREENODE_H_
#define SRC_BINARYTREENODE_H_

#include <climits>
#include <memory>

namespace myutils {
  const int BTNULL = INT_MAX;

  template <typename T>
  struct BinaryTreeNode {
      BinaryTreeNode(T d): data(d), parent(nullptr), size(0) { }

      T data;
      std::unique_ptr<BinaryTreeNode<T>> left, right;
      BinaryTreeNode<T> *parent;
      size_t size;
  };
} // myutils

#endif /* SRC_BINARYTREENODE_H_ */
