#include "DividenConquer.hpp"
using namespace std;

// Static Init
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
    // Mengembalikan nilai koefisien ke-idx
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
Polinom Polinom::operator+(const Polinom& A) {
    // Operator overloading + , menjumlahkan polinom A dengan polinom B
    if (A.getDegree() == this->degree) {
        // Jika derajat kedua polinom sama
        Polinom res(A.getDegree());
        for (int i = 0; i <= res.getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
            numOp++;
        }
        return res;
    }
    else if (A.getDegree() > this->degree) {
        // Jika derajat A > this->degree
        Polinom res(A.getDegree());
        for (int i = 0; i <= this->getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
            numOp++;
        }
        for (int i = this->getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = A.getCoef(i);
            numOp++;
        }
        return res;
    }
    else {
        // Jika this->degree > derajat A
        Polinom res(this->getDegree());
        for (int i = 0; i <= A.getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
            numOp++;
        }
        for (int i = A.getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = this->getCoef(i);
            numOp++;
        }
        return res;
    }
}

Polinom Polinom::operator-(const Polinom& A) {
    // Operator overloading - , mengurangi polinom A dengan polinom B
    if (A.getDegree() == this->degree) {
        // Jika derajat dua polinom sama
        Polinom res(A.getDegree());
        for (int i = 0; i <= res.getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
            numOp++;
        }
        return res;
    }
    else if (A.getDegree() > this->degree) {
        // Jika derajat A > this->degree
        Polinom res(A.getDegree());
        for (int i = 0; i <= this->getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
            numOp++;
        }
        for (int i = this->getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = 0 - A.getCoef(i);
            numOp++;
        }
        return res;
    }
    else {
        // Jika derajat this->degree > derajat A
        Polinom res(this->degree);
        for (int i = 0; i <= A.getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
            numOp++;
        }
        for (int i = A.getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = this->getCoef(i);
            numOp++;
        }
        return res;
    }
}

Polinom Polinom::operator*(const Polinom& A) {
    // Operator overloading * , implementasi algoritma divide anc conquer (algoritma perkalian karatsuba)
    if (A.getDegree() == 0 || this->getDegree() == 0) {
        Polinom C;
        C.coef[0] = A.getCoef(0)*this->getCoef(0);
        numOp++;
        return C;
    }
    else {
        int lowerSize = 0;
        if (A.getDegree() % 2 == 0) {        
           lowerSize = (A.getDegree()/2) - 1;
        }
        else {
            lowerSize = A.getDegree()/2;
        }
        int higherSize = (A.getDegree() - lowerSize - 1);
        Polinom ALower(lowerSize);
        Polinom AHigher(higherSize);
        Polinom BLower(lowerSize);
        Polinom BHigher(higherSize);

        for (int i = 0; i <= lowerSize; i++) {
            ALower.setCoef(i, A.getCoef(i));
            BLower.setCoef(i, this->getCoef(i));
        }
        for (int i = 0; i <= higherSize; i++) {
            AHigher.setCoef(i, A.getCoef(i + 1 + lowerSize));
            BHigher.setCoef(i , this->getCoef(i + 1 + lowerSize));
        }

        Polinom Y = (AHigher + ALower) * (BHigher + BLower);
        Polinom U = ALower * BLower;
        Polinom Z = AHigher * BHigher;

        Polinom res = U + (Y - U - Z).multiplyX(lowerSize+1) + Z.multiplyX((lowerSize+1)*2);
        return res;
    }
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
    // Memasukkan kofisien dari pengguna
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

Polinom Polinom::multiplyX(int d) {
    // Mengalikan pangkat polinom sebesar d
    // misal : (1+x^2).multiplyX(2) = (x^2+1+x^5)
    Polinom res(this->getDegree() + d);
    for (int i = d; i <= res.getDegree(); i++) {
        res.coef[i] = this->coef[i-d];
    }
    return res;
}
