#include <iostream>
#include "BulkItem.h"

using std::size_t;
using std::string;
using std::cout;
using std::endl;

namespace cppprimer {

BulkItem::BulkItem(string book, double p, double disc, int m):
    minQty(m), discount(disc) {
    this->book() = book;
    price = p;
}

double BulkItem::net_price(size_t cnt) const {
    if (cnt < minQty) {
        return cnt * price;
    } else {
        return cnt * price * (1 - discount);
    }
}

void BulkItem::memfcn(const BulkItem &d, const ItemBase &b) const {
    /* Source: Chapter 15.2.2
     * Description: see how protected var works.
     * Since ItemBase use protected on price,
     * BulkItem cannot access other ItemBase entities' price.
     * But BulkItem entities can access other BulkItems' price.
     */
    cout << "Self price: " << price << endl;
    cout << "Other's price: " << d.price << endl;
    // cout << "Base's price: " << b.price << endl;
}

} // cppprimer
