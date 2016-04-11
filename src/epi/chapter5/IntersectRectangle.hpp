#ifndef SRC_EPI_CHAPTER5_INTERSECTRECTANGLE_HPP_
#define SRC_EPI_CHAPTER5_INTERSECTRECTANGLE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class IntersectRectangle : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    struct Rectangle;

    IntersectRectangle():
        Solution("EPI Chapter 5.11",
                 "Find intersect rectangle of two rectangles.",
                 "Boundaries touch also count as intersect.") { }

    bool test();

    ~IntersectRectangle() { }

    Rectangle intersectRectangle(const Rectangle&, const Rectangle&);

    Rectangle intersectBruteForce(const Rectangle&, const Rectangle&);

private:
    bool isIntersect(const Rectangle&, const Rectangle&);
};

} // chapter5
} // epi

#endif /* SRC_EPI_CHAPTER5_INTERSECTRECTANGLE_HPP_ */
