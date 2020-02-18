#include "Polinom.hpp"
using namespace std;

// Constructor
Polinom::Polinom() {
    this->degree = 0;
    this->coef = new int[this->degree];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = 0;
    }
}
Polinom::Polinom(int degree) {
    this->degree = degree;
    this->coef = new int[this->degree];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = 0;
    }
}
// Copy constructor
Polinom::Polinom(const Polinom& p) {
    this->degree = p.degree;
    this->coef = new int[this->degree];
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
    this->degree = p.degree;
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = p.coef[i];
    }
    return *this;
}
// Getter setter
int Polinom::getCoef(int idx) const{
    return this->coef[idx];
}
int Polinom::getDegree() const{
    return this->degree;
}
void Polinom::setCoef(int idx, int val) {
    this->coef[idx] = val;
}
void Polinom::setDegree(int degree) {
    this->degree = degree;
}

// Other operator
Polinom operator+(const Polinom& A, const Polinom& B) {
    Polinom res(A.getDegree());
    for (int i = 0; i <= res.getDegree(); i++) {
        res.coef[i] = A.getCoef(i) + B.getCoef(i);
    }
    res.print();
    return res;
}

Polinom operator-(const Polinom& A, const Polinom& B) {
    Polinom res(A.getDegree());
    for (int i = 0; i <= res.getDegree(); i++) {
        res.coef[i] = A.getCoef(i) - B.getCoef(i);
    }
    res.print();
    return res;
}

Polinom operator*(const Polinom& A, const Polinom& B) {
    Polinom res(2*A.getDegree());
    for (int i = 0; i <= A.getDegree(); i++) {
        int idx = i;
        for (int j = 0; j <= B.getDegree(); j++) {
            res.coef[idx] += A.getCoef(i) * B.getCoef(j);
            idx ++;
        }
        idx = i;
    }
    res.print();
    return res;
}
// Other method
void Polinom::print() {
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
            this->coef[i] *= -1;
            cout << " - ";
            if (this->coef[i] != 1) {
                cout << this->coef[i];
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
    for (int i = 0; i <= this->degree; i++) {
        cin >> this->coef[i];
    }
}
int Polinom::solve(int x) {
    int temp = this->coef[0];
    int deg = x;
    for (int i = 1; i <= this->degree; i++) {
        temp += this->coef[i] * deg;
        deg *= x;
    }
    return temp;
}
void solveDivideConquer(const Polinom& A,const Polinom& B) {
    Polinom C;
    C = divideConquerRecc(A,B);
    C.print();
}

Polinom divideConquerRecc(const Polinom& A, const Polinom& B) {
    Polinom C(2*A.getDegree());

    // cout << A.getDegree() << endl;
    // cout << C.getDegree() << endl;
    if (A.getDegree() == 1) {
        C.coef[0] = A.getCoef(0) * B.getCoef(0);
        return C;
    }
    else {
        int n = A.getDegree()/2;
        Polinom AHigher(n);
        Polinom ALower(n - A.getDegree()%2);
        Polinom BHigher(n);
        Polinom BLower(n - A.getDegree()%2);

        for (int i = 0; i <= n; i++) {
            AHigher.setCoef(i, A.getCoef(i+n));
            ALower.setCoef(i, A.getCoef(i));
            BHigher.setCoef(i, B.getCoef(i+n));
            BLower.setCoef(i, B.getCoef(i));
        }

        // AHigher.print();
        // ALower.print();
        // BHigher.print();
        // BLower.print();

        Polinom Y = divideConquerRecc(AHigher + ALower, BHigher + BLower);
        Polinom U = divideConquerRecc(ALower, BLower);
        Polinom Z = divideConquerRecc(AHigher, BHigher);

        U.print();
        Y.print();
        Z.print();

        Polinom res(2*A.getDegree());

        for (int i = 0; i < A.getDegree()-1; i++) {
            res.coef[i] += U.getCoef(i);
            res.coef[i+n] += (Y.getCoef(i) - U.getCoef(i) - Z.getCoef(i));
            res.coef[i+(2*n)] += Z.getCoef(i);
        }

        return res;
    }
}