#ifndef SRC_MYUTILS_H_
#define SRC_MYUTILS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace myutils {

std::ifstream& open_file(std::ifstream &in, char *file);

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);

template <typename T>
std::string vec_to_string(const std::vector<T> &vec) {
    std::string output = "<";
    bool first_ele(true);
    for (typename std::vector<T>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        if (first_ele)
            first_ele = false;
        else
            output += ", ";

        output += std::to_string(*iter);
    }
    output += ">";

    return output;
}

} // myutils

#endif /* SRC_MYUTILS_H_ */
