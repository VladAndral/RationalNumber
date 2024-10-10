#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>

using namespace std;

class Rational {

    public:
    // Constructor
    Rational();
    Rational(int num, int den);

    // Gets n Sets
    int getNumerator() const;
    int getDenominator() const;
    bool set_value(int num, int den);

    // Operator Overloads
    Rational Multiply(const Rational& rat) const;
    Rational operator+(const Rational& rat) const;
    Rational operator-(const Rational& rat) const;
    Rational operator*(const Rational& rat) const;
    Rational operator/(const Rational& rat) const;

    /*
    The previous lines define operations between two fraction objects. But we have not yet defined how to print a
    Rational object, so if you try and print the product of two Rationals, you will get an error! Here we 
    define how to print out a rational (from the '<<')    
    */
    friend ostream& operator<<(ostream& stream, const Rational& rational);

    Rational reduceFraction();

    private:
    int numerator_; // Underscore is to let the reader know that the variable is private
    int denominator_;



};

#endif