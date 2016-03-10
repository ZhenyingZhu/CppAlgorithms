#ifndef SRC_MYUTILS_H_
#define SRC_MYUTILS_H_

#include <fstream>
#include <string>

namespace myutils {

std::ifstream& open_file(std::ifstream &in, char *file);
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);

}

#endif /* SRC_MYUTILS_H_ */
