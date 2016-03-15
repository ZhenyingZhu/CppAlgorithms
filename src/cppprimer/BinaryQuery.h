#ifndef SRC_CPPPRIMER_BINARYQUERY_H_
#define SRC_CPPPRIMER_BINARYQUERY_H_

#include <ostream>

#include "QueryBase.h"
#include "Query.h"

namespace cppprimer {

class BinaryQuery : public QueryBase {
    /* Source: Chapter 15.9.5
     * Description: Base class for and and or query.
     */
protected:
    BinaryQuery(Query left, Query right, std::string op):
        lhs(left), rhs(right), oper(op) { }

    // Abstract class
    std::ostream& display(std::ostream &os) const {
        // TODO
        //return os << "(" << lhs.display() << " " << oper << " " << rhs.display() << ")";
        return os;
    }

    const Query lhs, rhs;

    const std::string oper;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_BINARYQUERY_H_ */
