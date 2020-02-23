#include <iostream>
#include <time.h>
#include <chrono>
// #include "Polinom.hpp"
// #include "Bruteforce.hpp"
#include "DividenConquer.hpp"
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
    cout << "A(X) = ";
    A.print();
    Polinom B(n);
    B.inputRandom();
    // B.inputCoef();
    cout << "B(X) = ";
    B.print();
    Polinom C;
    // clock_t begin = clock();
    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto begin = chrono::steady_clock::now();
    C = A*B;
    // clock_t end = clock();
    auto end = chrono::steady_clock::now();
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Hasil perkalian : " << endl;
    cout << "A(X)B(X) = ";
    C.print();

    // double elapsedTime = double(end - begin)/CLOCKS_PER_SEC;
    // auto elapsedTime = duration_cast<microseconds>(end - begin);
    // cout << "Time elapsed : " << elapsedTime.count() << " microseconds" << endl;;
    // cout << "Time elapsed : " << elapsedTime << " microseconds" << endl;
    cout << "Time elapsed : " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << endl;
    cout << "Number of sum & multiplication : " << Polinom::getNumOp() << endl;

    return 0;
}   