#ifndef __BRUTE__FORCE__HPP__
#define __BRUTE__FORCE__HPP__

#include <iostream>
#include <time.h>
using namespace std;

class Polinom {
    private :
        int *coef;          // Container koefisien polinom
        int degree;         // Pangkat tertinggi polinom
        static int numOp;   // Counter operator
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
        Polinom operator*(const Polinom& A);
        // Other method
        void print();
        void inputCoef();
        void inputRandom();
};

#endif