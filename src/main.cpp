#include <iostream>
#include "Polinom.hpp"
// #include "Bruteforce.hpp"
// #include "DividenConquer.hpp"
using namespace std;

int main() {
    Polinom A(4);
    A.inputRandom();
    A.print();
    Polinom B(4);
    B.inputRandom();
    B.print();
    // A+B;
    A*B;
    solveDivideConquer(A,B);
    // A-B-C;
    // A+B;
}   