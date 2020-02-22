#ifndef __DIVIDE__AND__CONQUER__HPP__
#define __DIVIDE__AND__CONQUER__HPP__

#include <iostream>
#include <time.h>
using namespace std;

class Polinom {
    private :
        int *coef;
        int degree;
        static int numOp;
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
        static int getNumOp();
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
        Polinom multiplyX(int d);
};

#endif