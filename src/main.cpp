#include <iostream>
#include <time.h>
// #include "Polinom.hpp"
#include "Bruteforce.hpp"
// #include "DividenConquer.hpp"
using namespace std;

int main() {
    srand(time(0));
    Polinom A(1);
    A.inputRandom();
    // A.inputCoef();
    A.print();
    Polinom B(1);
    B.inputRandom();
    // B.inputCoef();
    B.print();
    Polinom C;
    clock_t begin = clock();
    C = A*B;
    clock_t end = clock();
    double elapsedTime = double(end - begin) / 1000;
    C.print();
    // A*B;
    // solveDivideConquer(A,B);
    cout << "Time elapsed : " << elapsedTime << " microseconds" << endl;
    cout << "Number of sum & multiplication : " << Polinom::getNumOp() << endl;
    // A-B-C;
    // A+B;
    // A.~Polinom();
    // B.~Polinom();
    // C.~Polinom();
    return 0;
}   