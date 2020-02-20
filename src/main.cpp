#include <iostream>
#include "Polinom.hpp"
// #include "Bruteforce.hpp"
// #include "DividenConquer.hpp"
using namespace std;

int main() {
    srand(time(0));
    Polinom A(1);
    // A.inputRandom();
    A.inputCoef();
    A.print();
    Polinom B(1);
    // B.inputRandom();
    B.inputCoef();
    B.print();
    Polinom C;
    C = A*B;
    // A*B;
    cout << C.getDegree() << endl;
    C.print();
    // (A*B).print();
    // Polinom D;
    // solveDivideConquer(A,B);
    cout << "hai" << endl;
    // A-B-C;
    // A+B;
    return 0;
}   