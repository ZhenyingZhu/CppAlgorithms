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
void print_vec(std::vector<T> &vec) {
    std::cout << "<";
    bool first_ele(true);
    for (typename std::vector<T>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        if (first_ele)
            first_ele = false;
        else
            std::cout << ", ";

        std::cout << *iter;
    }
    std::cout << ">";
}

} // myutils

#endif /* SRC_MYUTILS_H_ */
