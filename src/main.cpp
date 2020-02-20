#include <iostream>
#include "Polinom.hpp"
// #include "Bruteforce.hpp"
// #include "DividenConquer.hpp"
using namespace std;

int main() {
    srand(time(0));
    Polinom A(3);
    A.inputRandom();
    // A.inputCoef();
    A.print();
    Polinom B(3);
    B.inputRandom();
    // B.inputCoef();
    B.print();
    Polinom C;
    C = A*B;
    A*B;
    // cout << C.getDegree() << endl;
    cout << C.getCoef(0) << endl;
    for (int i = 0; i <= C.getDegree(); i++) {
        cout << C.getCoef(i) << endl;
    }
    C.print();
    // (A*B).print();
    // solveDivideConquer(A,B);
    // A-B-C;
    // A+B;
}   