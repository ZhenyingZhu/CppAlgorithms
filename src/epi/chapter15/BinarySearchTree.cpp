#include "BinarySearchTree.hpp"

#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <climits>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::set;
using std::sqrt;
using std::min;
using std::next;
using std::move;
using std::ostream;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    class BinarySearchTree::BST {
    public:
        bool bstInsert(int key);

        bool bstDelete(int key);

    private:
        std::unique_ptr<myutils::BSTNode<int>> root_ = nullptr;

    };

    bool BinarySearchTree::test() {
        vector<int> array = {2,3,5,7,11,13,17,19,23};

        unique_ptr<BSTNode<int>> res = buildMinHeightBSTFromSortedArray(array);
        if (res.get()->data != 11) {
            cout << "Should be " << 11 << endl;
            cout << "Result " << res.get()->data << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
