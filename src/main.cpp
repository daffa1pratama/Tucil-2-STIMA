#include <iostream>
#include "Polinom.hpp"
using namespace std;

int main() {
    Polinom A(2);
    A.inputCoef();
    A.print();
    Polinom B(2);
    B.inputCoef();
    B.print();
    A+B;
    A*B;
    solveDivideConquer(A,B);
    // A-B-C;
    // A+B;
}