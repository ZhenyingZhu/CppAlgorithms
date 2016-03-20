#ifndef SRC_SMARTPTR_H_
#define SRC_SMARTPTR_H_

#include <string>

#include "Solution.h"

class SmartPtr {
public:
    SmartPtr(const Solution *solution);

    SmartPtr(const SmartPtr &copy);

    SmartPtr& operator=(const SmartPtr &copy);

    ~SmartPtr() {
        descUse();
    }

    std::string displaySource();

    std::string displayDescription();

    bool runTest();

private:
    void descUse();

    const Solution *solPtr;
    std::size_t *use;
};

#endif /* SRC_SMARTPTR_H_ */
