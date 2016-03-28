#ifndef SRC_SMARTPTR_H_
#define SRC_SMARTPTR_H_

#include <string>

#include "Solution.h"

namespace myutils {

class SmartPtr {
public:
    SmartPtr(Solution *solution);

    SmartPtr(const SmartPtr &copy);

    SmartPtr& operator=(const SmartPtr &copy);

    ~SmartPtr() {
        descUse();
    }

    std::string displaySource();

    std::string displayTitle();

    std::string displayDescription();

    bool runTest();

private:
    void descUse();

    Solution *solPtr;
    std::size_t *use;
};

} // myutils

#endif /* SRC_SMARTPTR_H_ */
