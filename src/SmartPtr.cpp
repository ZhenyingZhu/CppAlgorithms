#include <iostream>
#include <string>

#include "SmartPtr.h"

using std::string;

SmartPtr::SmartPtr(const Solution & solution):
        solPtr(&solution), use(new std::size_t(1)) { }


SmartPtr::SmartPtr(const SmartPtr &copy):
    solPtr(copy.solPtr), use(copy.use) {
        ++*use;
}

SmartPtr& SmartPtr::operator=(const SmartPtr &copy) {
    descUse(); // release itself first

    solPtr = copy.solPtr;
    use = copy.use;
    ++*use;
    return *this;
}

void SmartPtr::descUse() {
    --*use;
    if (*use == 0) {
        delete solPtr;
        delete use;
    }
}

string SmartPtr::display() {
    return solPtr->getSource();
}
