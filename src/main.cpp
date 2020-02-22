#include <iostream>
#include <time.h>
// #include "Polinom.hpp"
#include "Bruteforce.hpp"
// #include "DividenConquer.hpp"
using namespace std;

int main() {
    srand(time(0));
    cout << "================================" << endl;
    cout << "**** KALKULATOR POLINOMIAL *****" << endl;
    cout << "================================" << endl;
    int n;
    cout << "Masukan derajat tertinggi (n) : ";
    cin >> n;
    Polinom A(n);
    A.inputRandom();
    // A.inputCoef();
    A.print();
    Polinom B(n);
    B.inputRandom();
    // B.inputCoef();
    B.print();
    Polinom C;
    clock_t begin = clock();
    C = A*B;
    clock_t end = clock();
    double elapsedTime = double(end - begin);
    C.print();

    cout << "Time elapsed : " << elapsedTime << " microseconds" << endl;
    cout << "Number of sum & multiplication : " << Polinom::getNumOp() << endl;

    return 0;
}   