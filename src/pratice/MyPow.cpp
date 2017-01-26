#include <iostream>

using namespace std;

double myPow(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    if (n == -1)
        return 1.0 / x;

    double half = myPow(x, n / 2);
    double tmp = half * half;
    if (n % 2 == 0) {
        return tmp;
    } else if (n > 0) {
        return tmp * x;
    } else {
        return tmp / x;
    }
}

int main() {
    cout << myPow(1.0, 1) << endl;
    cout << myPow(2.0, 2) << endl;
    cout << myPow(2.0, 3) << endl;
    cout << myPow(2.0, -1) << endl;
    cout << myPow(2.0, -2) << endl;

    return 0;
}
