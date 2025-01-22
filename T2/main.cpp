
#include <iostream>
#include "Racional.h"

using namespace std;

int main() {

    Racional r1(-4, -6);
    Racional r2(6, 10);
    Racional r3(2,3);
    Racional r4(3,3);

    cout << boolalpha << endl;
    cout << "r1         => " << r1 << "   [deveria ser 2/3]" << endl;
    cout << "r2         => " << r2 << "   [deveria ser 3/5]" << endl;
    cout << "r3         => " << r3 << "   [deveria ser 2/3]" << endl;
    cout << "r4         => " << r4 << "     [deveria ser 1]" << endl;
    cout << "(r1 + r2)  => " << r1 + r2 << " [deveria ser 19/15]" << endl;
    cout << "(r1 - r2)  => " << r1 - r2 << "  [deveria ser 1/15]" << endl;
    cout << "(r1 * r2)  => " << r1 * r2 << "   [deveria ser 2/5]" << endl;
    cout << "(r1 / r2)  => " << r1 / r2 << "  [deveria ser 10/9]" << endl;

    cout << "(r1 < r2)  => " << (r1 < r2) << " [deveria ser false]" << endl;
    cout << "(r1 < r3)  => " << (r1 < r3) << " [deveria ser false]" << endl;
    cout << "(r1 <= r2) => " << (r1 <= r2) << " [deveria ser false]" << endl;
    cout << "(r1 <= r3) => " << (r1 <= r3) << "  [deveria ser true]" << endl;
    cout << "(r1 == r2) => " << (r1 == r2) << " [deveria ser false]" << endl;
    cout << "(r1 == r3) => " << (r1 == r3) << "  [deveria ser true]" << endl;
    cout << "(r1 != r2) => " << (r1 != r2) << "  [deveria ser true]" << endl;
    cout << "(r1 != r3) => " << (r1 != r3) << " [deveria ser false]" << endl;
    cout << "(r1 >= r2) => " << (r1 >= r2) << "  [deveria ser true]" << endl;
    cout << "(r1 >= r3) => " << (r1 >= r3) << "  [deveria ser true]" << endl;
    cout << "(r1 > r2)  => " << (r1 > r2) << "  [deveria ser true]" << endl;
    cout << "(r1 > r3)  => " << (r1 > r3) << " [deveria ser false]" << endl;
    cout << endl;

    return 0;
}

