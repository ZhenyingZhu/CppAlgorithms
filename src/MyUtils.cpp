#include "MyUtils.h"

#include <fstream>
#include <vector>
#include <iostream>

using std::ifstream;
using std::string;
using std::vector;

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

} // myutils
