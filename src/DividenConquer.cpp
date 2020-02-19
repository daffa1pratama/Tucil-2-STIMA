#include "DividenConquer.hpp"
using namespace std;

// Constructor
Polinom::Polinom() {
    this->degree = 1;
    this->coef = new int[this->degree];
    for (int i = 0; i < this->degree; i++) {
        this->coef[i] = 0;
    }
}
Polinom::Polinom(int degree) {
    this->degree = degree+1;
    this->coef = new int[this->degree];
    for (int i = 0; i < this->degree; i++) {
        this->coef[i] = 0;
    }
}
// Copy constructor
Polinom::Polinom(const Polinom& p) {
    this->degree = p.degree;
    this->coef = new int[this->degree];
    for (int i = 0; i < this->degree; i++) {
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
    for (int i = 0; i < this->degree; i++) {
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
    Polinom res(A.getDegree() - 1);
    for (int i = 0; i < res.getDegree(); i++) {
        res.coef[i] = A.getCoef(i) + B.getCoef(i);
    }
    // res.print();
    return res;
}

Polinom operator-(const Polinom& A, const Polinom& B) {
    Polinom res(A.getDegree() - 1);
    for (int i = 0; i < res.getDegree(); i++) {
        res.coef[i] = A.getCoef(i) - B.getCoef(i);
    }
    // res.print();
    return res;
}

Polinom operator*(const Polinom& A, const Polinom& B) {
    Polinom res(2*A.getDegree());
    for (int i = 0; i < A.getDegree(); i++) {
        int idx = i;
        for (int j = 0; j < B.getDegree(); j++) {
            res.coef[idx] += A.getCoef(i) * B.getCoef(j);
            idx++;
        }
        idx = i;
    }
    res.print();
    return res;
}
// Other method
void Polinom::print() {
    cout << this->coef[0];
    for (int i = 1; i < this->degree; i++) {
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
    for (int i = 0; i < this->degree; i++) {
        cin >> this->coef[i];
    }
}
void Polinom::inputRandom() {
    srand(time(0));
    for (int i = 0; i < this->degree; i++) {
        this->coef[i] = rand() % 11 - rand() % 11;
    }

}
int Polinom::solve(int x) {
    int temp = this->coef[0];
    int deg = x;
    for (int i = 1; i < this->degree; i++) {
        temp += this->coef[i] * deg;
        deg *= x;
    }
    return temp;
}
void solveDivideConquer(const Polinom& A,const Polinom& B) {
    Polinom C(2*A.getDegree()-1);
    Polinom Ax(A);
    Polinom Bx(B);
    Ax.setDegree(A.getDegree());
    Bx.setDegree(B.getDegree());
    C = divideConquerRecc(Ax, Bx);
    C.print();
}

Polinom divideConquerRecc(const Polinom& A, const Polinom& B) {
    if (A.getDegree() == 1) {
        Polinom C;
        C.coef[0] = A.getCoef(0) * B.getCoef(0);
        return C;
    }
    else {
        // cout << "ini :" << A.getDegree() << endl;
        int n = A.getDegree()/2;
        Polinom AHigher(A.getDegree() - n - 1);
        Polinom ALower(n - 1);
        Polinom BHigher(B.getDegree() - n - 1);
        Polinom BLower(n - 1);
        Polinom AHighLow(A.getDegree() - n - 1);
        Polinom BHighLow(B.getDegree() - n - 1);

        // cout << "Ahighlow : " << AHighLow.getDegree() << endl;
        // cout << "Bhighlow : " << BHighLow.getDegree() << endl;

        if (AHigher.getDegree() == ALower.getDegree()) { //Komponen genap
            for (int i = 0; i < n; i++) {
                AHigher.setCoef(i, A.getCoef(i+n));
                ALower.setCoef(i, A.getCoef(i));
                BHigher.setCoef(i, B.getCoef(i+n));
                BLower.setCoef(i, B.getCoef(i));
            }
            AHighLow = AHigher + ALower;
            BHighLow = BHigher + BLower;
        }
        else { //Komponen ganjil
            for (int i = 0; i < n; i++) {
                ALower.setCoef(i, A.getCoef(i));
                BLower.setCoef(i, B.getCoef(i));
            }
            for (int i = 0; i <= n; i++) {
                AHigher.setCoef(i, A.getCoef(i+n));
                BHigher.setCoef(i, B.getCoef(i+n));
            }
            AHighLow = AHigher + ALower;
            BHighLow = BHigher + BLower;
            AHighLow.setCoef(AHighLow.getDegree()-1, AHigher.getCoef(AHigher.getDegree()-1));
            BHighLow.setCoef(BHighLow.getDegree()-1, BHigher.getCoef(BHigher.getDegree()-1));
        }

        // cout << "========" << endl;
        // AHigher.print();
        // ALower.print();
        // BHigher.print();
        // BLower.print();
        // cout << "========" << endl;

        // AHighLow.print();
        // BHighLow.print();

        Polinom Y(n);
        Y = divideConquerRecc(AHighLow, BHighLow);
        Polinom U(n);
        U = divideConquerRecc(ALower, BLower);
        Polinom Z(n);
        Z = divideConquerRecc(AHigher, BHigher);
        
        // U.print();
        // Y.print();
        // Z.print();

        Polinom res((2*A.getDegree())-2);
        for (int i = 0; i < A.getDegree()-1; i++) {
            res.coef[i] += U.getCoef(i);
            res.coef[i+n] += (Y.getCoef(i) - U.getCoef(i) - Z.getCoef(i));
            res.coef[i+(2*n)] += Z.getCoef(i);
        }

        cout << "Z : " << Z.getDegree() << endl;

        return res;
    }
}

