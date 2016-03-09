#include <fstream>
#include <vector>
#include <iostream>
#include "MyUtils.h"

using namespace std;

namespace myutils {

extern ifstream& open_file(ifstream &in, char *file) {
    /* Open a file by name and bind it to a stream.
     */
    in.close();
    in.clear();
    in.open(file);
    return in;
}

extern string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr == 1) ? word : word + ending;
}

extern void print_vec(vector<int> A) {
    for (vector<int>::const_iterator iter = A.begin(); iter != A.end(); ++iter) {
        cout << *iter;
    }
}

}
