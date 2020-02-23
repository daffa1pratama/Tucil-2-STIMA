#include "Bruteforce.hpp"
using namespace std;

// Static init
// Inisialisasi counter operator
int Polinom::numOp = 0;

// Constructor
Polinom::Polinom() {
    // Default constructor, meng-assign degree = 0 dan semua koefisien = 0
    this->degree = 0;
    this->coef = new int[this->degree+1];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = 0;
    }
}
Polinom::Polinom(int degree) {
    // Meng-assign degree = degree dan semua koeifisen = 0
    if (degree < 0) {
        this->degree = 0;
    }
    else {
        this->degree = degree;
    }
    this->coef = new int[this->degree+1];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = 0;
    }
}
// Copy constructor
Polinom::Polinom(const Polinom& p) {
    // Mengassign degree = p.degree dan semua koefisien = p.coef
    this->degree = p.degree;
    this->coef = new int[this->degree+1];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = p.coef[i];
    }
}
// Destructor
Polinom::~Polinom() {
    delete[]this->coef;
}
// Operator assignment
Polinom& Polinom::operator=(const Polinom& p) {
    // Operator overloading assignment, mengassign degree = p.degree dan semua koefisien = p.coef
    this->degree = p.degree;
    this->coef = new int[this->degree+1];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = p.coef[i];
    }
    return *this;
}
// Getter setter
int Polinom::getCoef(int idx) const{
    // Mengembalikan nilai koefisien ke-idx
    return this->coef[idx];
}
int Polinom::getDegree() const{
    // Mengembalikan nilai derajat tertinggi
    return this->degree;
}
int Polinom::getNumOp() {
    // Mengembalikan jumlah operator
    return numOp;
}
void Polinom::setCoef(int idx, int val) {
    // Mengassign koefisien ke-idx = val
    this->coef[idx] = val;
}
void Polinom::setDegree(int degree) {
    // Mengassign degree = degree
    this->degree = degree;
}

// Other operator
Polinom Polinom::operator*(const Polinom& A) {
    // Operator overloading * , implementasi algoritma bruteforce untuk perkalian 2 polinom
    Polinom res(this->getDegree()+A.getDegree());
    int idx;
    for (int i = 0; i <= this->getDegree(); i++) {
        idx = i;
        for (int j = 0; j <= A.getDegree(); j++) {
            res.coef[idx] += (this->getCoef(i) * A.getCoef(j));
            numOp+=2;
            idx++;
        }
    }
    numOp -= (2*A.getDegree()+1);
    return res;
}

// Other method
void Polinom::print() {
    // Mencetak polinom ke layar
    cout << this->coef[0];
    for (int i = 1; i <= this->degree; i++) {
        if (this->coef[i] > 0) {
            cout << " + ";
            if (this->coef[i] != 1) {
                cout << this->coef[i];
            }
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }
        else if (this->coef[i] < 0) {
            int temp = this->coef[i];
            temp *= -1;
            cout << " - ";
            if (temp != 1) {
                cout << temp;
            }
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
    cout << endl;
}

void Polinom::inputCoef() {
    // Memasukkan koefisien dari pengguna
    for (int i = 0; i <= this->degree; i++) {
        cin >> this->coef[i];
    }
}

void Polinom::inputRandom() {
    // Memasukkan koefisien yang dibangkitkan secara acak
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = rand() % 11 - rand() % 11;
        while (this->coef[i] == 0) {
            this->coef[i] = rand() % 11 - rand() % 11;
        }
    }
}