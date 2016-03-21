#include <stddef.h>
#include <vector>

#include "SolutionCollection.h"
#include "SmartPtr.h"

using std::vector;

namespace myutils {

SolutionCollection *SolutionCollection::instance = NULL;

SolutionCollection* SolutionCollection::getInstance() {
    if (!instance) {
        instance = new SolutionCollection();
    }
    return instance;
}

void SolutionCollection::insertSolution(const SmartPtr& solPtr) {
    solVec.push_back(solPtr);
}

bool SolutionCollection::checkSolutions() {
    for (vector<SmartPtr>::iterator iter = solVec.begin(); iter != solVec.end(); ++iter) {
        if ( !iter->runTest() ) {
            return false;
        }
    }

    return true;
}

} // myutils
