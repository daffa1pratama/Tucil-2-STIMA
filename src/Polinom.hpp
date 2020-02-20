#include <iostream>
#include <time.h>
using namespace std;

class Polinom {
    private :
        int *coef;
        int degree;
    public  :
        // Constructor
        Polinom();
        Polinom(int degree);
        // Copy constructor
        Polinom(const Polinom& p);
        // Destructor
        ~Polinom();
        // Operator assignment
        Polinom& operator=(const Polinom& p);
        // Getter setter
        int getCoef(int idx) const;
        int getDegree() const;
        void setCoef(int idx, int val);
        void setDegree(int degree);
        // Other operator
        Polinom operator+(const Polinom& A);
        Polinom operator-(const Polinom& A);
        Polinom operator*(const Polinom& A);
        // Other method
        void print();
        void inputCoef();
        void inputRandom();
        int solve(int x);
        Polinom multiplyX(int d);
        friend void solveDivideConquer(const Polinom& A,const Polinom& B);
        friend Polinom divideConquerRecc(const Polinom& A, const Polinom& B);
};