#include "IntersectRectangle.hpp"

#include <iostream>
#include <algorithm>

using std::ostream;
using std::max;
using std::min;
using std::cout;
using std::endl;

namespace epi {
namespace chapter5 {

    struct IntersectRectangle::Rectangle {
        bool operator==(const Rectangle &other);

        int x, y, width, height;
    };

    bool IntersectRectangle::Rectangle::operator==(const Rectangle &other) {
        if (x == other.x && y == other.y && width == other.width && height == other.height)
            return true;

        return false;
    }

    bool IntersectRectangle::isIntersect(const Rectangle &R1, const Rectangle &R2) {
        return R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
            R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y;
    }

    IntersectRectangle::Rectangle IntersectRectangle::intersectRectangle(
            const Rectangle &R1, const Rectangle &R2) {
        if (isIntersect(R1, R2)) {
            return{ max(R1.x, R2.x), max(R1.y, R2.y),
                min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
                min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)};
        }
        return{ 0, 0, -1, -1 };
    }

    ostream& operator<<(ostream &os, const IntersectRectangle::Rectangle &rec) {
        os << "(" << rec.x << "," << rec.y << ") " << "w: " << rec.width << " h: " << rec.height;
        return os;
    }

    bool IntersectRectangle::test() {
        Rectangle r1 = { 1, 2, 3, 2 };
        Rectangle r2 = { 2, 1, 3, 2 };
        cout << intersectRectangle(r1, r2) << endl;

        return true;
    }
} // chapter 5
} // epi
