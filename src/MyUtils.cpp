#include "MyUtils.h"

#include <fstream>
#include <vector>
#include <memory>
#include <iostream>

#include "BinaryTreeNode.h"

using std::ifstream;
using std::string;
using std::vector;
using std::unique_ptr;
using std::move;

namespace myutils {

extern ifstream& open_file(ifstream &in, char *file) {
    // Open a file by name and bind it to a stream.
    in.close();
    in.clear();
    in.open(file);
    return in;
}

extern string make_plural(size_t ctr, const string &word, const string &ending) {
    // Return a the plural form of a word
    return (ctr == 1) ? word : word + ending;
}

extern unique_ptr<BinaryTreeNode<int>> createPreOrderIntBTree(const vector<int> &vec, size_t *pos) {
    // use 256 to indicate a null ptr
    if (*pos >= vec.size() || vec[*pos] == myutils::BTNULL) {
        return nullptr;
    }

    unique_ptr<BinaryTreeNode<int>> root( new BinaryTreeNode<int>{vec[*pos]} );
    root.get()->parent = nullptr;
    ++(*pos);
    root.get()->left = move( createPreOrderIntBTree(vec, pos) );
    if (root.get()->left)
        root.get()->left.get()->parent = root.get();
    ++(*pos);
    root.get()->right = move( createPreOrderIntBTree(vec, pos) );
    if (root.get()->right)
        root.get()->right.get()->parent = root.get();

    return root;
}

} // myutils
