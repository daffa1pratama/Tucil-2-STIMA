#include "Polinom.hpp"
using namespace std;

// Constructor
Polinom::Polinom() {
    this->degree = 0;
    this->coef = new int[this->degree+1];
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = 0;
    }
}
Polinom::Polinom(int degree) {
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
    this->degree = p.degree;
    this->coef = new int[this->degree+1];
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
Polinom Polinom::operator+(const Polinom& A) {
    if (A.getDegree() == this->degree) {
        Polinom res(A.getDegree());
        for (int i = 0; i <= res.getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
        }
        return res;
    }
    else if (A.getDegree() > this->degree) {
        Polinom res(A.getDegree());
        for (int i = 0; i <= this->getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
        }
        for (int i = this->getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = A.getCoef(i);
        }
        return res;
    }
    else {
        Polinom res(this->getDegree());
        for (int i = 0; i <= A.getDegree(); i++) {
            res.coef[i] = A.getCoef(i) + this->coef[i];
        }
        for (int i = A.getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = this->getCoef(i);
        }
        return res;
    }
}

Polinom Polinom::operator-(const Polinom& A) {
    if (A.getDegree() == this->degree) {
        Polinom res(A.getDegree());
        for (int i = 0; i <= res.getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
        }
        return res;
    }
    else if (A.getDegree() > this->degree) {
        Polinom res(A.getDegree());
        for (int i = 0; i <= this->getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
        }
        for (int i = this->getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = 0 - A.getCoef(i);
        }
        return res;
    }
    else {
        Polinom res(this->degree);
        for (int i = 0; i <= A.getDegree(); i++) {
            res.coef[i] = this->coef[i] - A.getCoef(i);
        }
        for (int i = A.getDegree() + 1; i <= res.getDegree(); i++) {
            res.coef[i] = this->getCoef(i);
        }
        return res;
    }
}

Polinom Polinom::operator*(const Polinom& A) {
    Polinom res(this->getDegree()+A.getDegree());
    int idx;
    cout << this->getDegree() << endl;
    res.print();
    for (int i = 0; i <= this->getDegree(); i++) {
        // cout << "AAA" << endl;
        idx = i;
        for (int j = 0; j <= A.getDegree(); j++) {
            // cout << "BBB" << endl;
            res.coef[idx] += (this->getCoef(i) * A.getCoef(j));
            idx++;
        }
    }
    // res.print();
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
    for (int i = 0; i <= this->degree; i++) {
        cin >> this->coef[i];
    }
}

void Polinom::inputRandom() {
    for (int i = 0; i <= this->degree; i++) {
        this->coef[i] = rand() % 11 - rand() % 11;
        while (this->coef[i] == 0) {
            this->coef[i] = rand() % 11 - rand() % 11;
        }
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

Polinom Polinom::multiplyX(int d) {
    Polinom res(this->getDegree() + d);
    for (int i = d; i <= res.getDegree(); i++) {
        res.coef[i] = this->coef[i-d];
    }
    return res;
}

void solveDivideConquer(const Polinom& A,const Polinom& B) {
    Polinom C;
    C = divideConquerRecc(A, B);
    C.print();
}

Polinom divideConquerRecc(const Polinom& A, const Polinom& B) {
    if (A.getDegree() == 0 || B.getDegree() == 0) {
        Polinom C;
        C.coef[0] = A.getCoef(0)*B.getCoef(0);
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
        // int lowerSize = A.getDegree()/2 - 1;
        int higherSize = (A.getDegree() - lowerSize - 1);
        Polinom ALower(lowerSize);
        Polinom AHigher(higherSize);
        Polinom BLower(lowerSize);
        Polinom BHigher(higherSize);

        for (int i = 0; i <= lowerSize; i++) {
            ALower.setCoef(i, A.getCoef(i));
            BLower.setCoef(i, B.getCoef(i));
        }
        for (int i = 0; i <= higherSize; i++) {
            AHigher.setCoef(i, A.getCoef(i + 1 + lowerSize));
            BHigher.setCoef(i , B.getCoef(i + 1 + lowerSize));
        }

        Polinom AHighLow = AHigher + ALower;
        Polinom BHighLow = BHigher + BLower;

        Polinom Y = divideConquerRecc(AHighLow, BHighLow);
        Polinom U = divideConquerRecc(ALower, BLower);
        Polinom Z = divideConquerRecc(AHigher, BHigher);
        
        return U + (Y - U - Z).multiplyX(lowerSize+1) + Z.multiplyX((lowerSize+1)*2);
    }
}

