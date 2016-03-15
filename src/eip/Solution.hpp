#include <string>

#ifndef SRC_EIP_SOLUTION_HPP_
#define SRC_EIP_SOLUTION_HPP_

namespace eip {

  class Solution {
  public:
      Solution(std::string questionSource, std::string questionDescription);

      bool test();

      ~Solution() {}

  private:
      std::string questionSource_;
      std::string questionDescription_;
  };
}


#endif /* SRC_EIP_SOLUTION_HPP_ */
