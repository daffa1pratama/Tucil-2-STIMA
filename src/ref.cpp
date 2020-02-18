#include "ref.hpp"
#include <iostream>

using namespace std;

Polinom::Polinom() {
    derajat = 0;
    for (int i=0;i<MAX_LENGTH;i++) {
        koef[i] = 0;
    }
}

Polinom::Polinom(int n) {
    derajat = n;
    for (int i=0;i<MAX_LENGTH;i++) {
        koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& P) {
    derajat = P.derajat;
    for (int i=0;i<MAX_LENGTH;i++) {
        koef[i] = P.koef[i];
    }
}

Polinom::~Polinom() {
    // gaada new, makanya kosong
}

Polinom& Polinom::operator=(const Polinom& P) {
    derajat = P.derajat;
    for (int i=0;i<MAX_LENGTH;i++) {
        koef[i] = P.koef[i];
    }
    return *this;
}

//
int Polinom::getKoefAt(int idx) const {
    return koef[idx];
}

int Polinom::getDerajat() const {
    return derajat;
}

void Polinom::setKoefAt(int idx, int val) {
    koef[idx] = val;
}

void Polinom::setDerajat(int n) {
    derajat = n;
}

//
Polinom operator+(const Polinom& A, const Polinom& B) {
    Polinom C;
    if (A.getDerajat() > B.getDerajat()) {
        C.setDerajat(A.getDerajat());
    } else {
        C.setDerajat(B.getDerajat());
    }
    for (int i=0;i<=C.getDerajat();i++) {
        C.koef[i] = A.koef[i] + B.koef[i];
    }
    return C;
}

Polinom operator-(const Polinom& A, const Polinom& B) {
    Polinom C;
    if (A.getDerajat() > B.getDerajat()) {
        C.setDerajat(A.getDerajat());
    } else {
        C.setDerajat(B.getDerajat());
    }
    for (int i=0;i<=C.getDerajat();i++) {
        C.koef[i] = A.koef[i] - B.koef[i];
    }
    return C;
}

Polinom operator*(const Polinom& A, const int x) {
    Polinom C(A.derajat);
    for (int i=0;i<=C.derajat;i++) {
        C.koef[i] = A.koef[i] * x;
    }
    return C;
}

Polinom operator*(const int x, const Polinom& A) {
    Polinom C(A.derajat);
    for (int i=0;i<=C.derajat;i++) {
        C.koef[i] = A.koef[i] * x;
    }
    return C;
}

Polinom operator/(const Polinom& A, const int x) {
    Polinom C(A.derajat);
    for (int i=0;i<=C.derajat;i++) {
        C.koef[i] = A.koef[i] / x;
    }
    return C;
}

//
void Polinom::input() {
    for (int i=0;i<=derajat;i++) {
        cin >> koef[i];
    }
}

void Polinom::printKoef() {
    for (int i=0;i<=derajat;i++) {
        cout << koef[i] << endl;
    }
}

int Polinom::substitute(int x) {
    int ret = 0, p = 1;
    for (int i=0;i<=derajat;i++) {
        ret += p * koef[i];
        p *= x;
    }
    return ret;
}

Polinom Polinom::derive() {
    if (derajat > 0) {
        Polinom P(derajat - 1);
        for (int i=0;i<=P.derajat;i++) {
            P.koef[i] = (i+1) * koef[i+1];
        }
        return P;
    } else {
        Polinom P;
        return P;
    }
}

void Polinom::print() {
    cout << koef[0];
    for (int i=1;i<=derajat;i++) {
        if (koef[i] > 0) cout << "+" << koef[i] << "x^" << i;
        else if (koef[i] == 0) continue;
        else cout << koef[i] << "x^" << i;
    }
    cout << endl;   // biar cakep
}