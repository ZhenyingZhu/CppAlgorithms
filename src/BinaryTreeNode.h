#ifndef SRC_BINARYTREENODE_H_
#define SRC_BINARYTREENODE_H_

#include <memory>

namespace myutils {
  template <typename T>
  struct BinaryTreeNode {
      T data;
      std::unique_ptr<BinaryTreeNode<T>> left, right;
      BinaryTreeNode<T> *parent;
  };
} // myutils

#endif /* SRC_BINARYTREENODE_H_ */
