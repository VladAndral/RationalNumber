#include "Rational.h"

using namespace std; // Needed for ostream

/*
		CONSTRUCTOR
*/

// If you initialize a Rational object w/ no params, this is the default loadout
Rational::Rational() : numerator_(5), denominator_(3) { }

Rational::Rational(int num, int den) : numerator_(num), denominator_(den) {
	reduceFraction();
}

/*
		SETTERS AND GETTERS
*/

int Rational::getNumerator() const {
	return numerator_;
}

int Rational::getDenominator() const {
	return denominator_;
}

/*
		OPERATOR OVERLOADS
*/

Rational Rational::Multiply(const Rational& refToRatObj) const {
	int numerator = numerator_ * refToRatObj.numerator_;
	int denominator = denominator_ * refToRatObj.denominator_;
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

Rational Rational::operator+(const Rational& refToRatObj) const { 
	int numerator = (numerator_*refToRatObj.denominator_) + (refToRatObj.numerator_*denominator_);
	int denominator = (denominator_*refToRatObj.denominator_) + (refToRatObj.denominator_*denominator_);
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

Rational Rational::operator-(const Rational& refToRatObj) const {
	int numerator = (numerator_*refToRatObj.denominator_) - (refToRatObj.numerator_*denominator_);
	int denominator = (denominator_*refToRatObj.denominator_) - (refToRatObj.denominator_*denominator_);
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

Rational Rational::operator*(const Rational& refToRatObj) const {
	int numerator = numerator_ * refToRatObj.numerator_;
	int denominator = denominator_ * refToRatObj.denominator_;
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

Rational Rational::operator/(const Rational& refToRatObj) const {
	int numerator = denominator_ * refToRatObj.numerator_;
	int denominator = numerator_ * refToRatObj.denominator_;
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}


/*
The previous lines define operations between two fraction objects. But we have not yet defined how to print a
Rational object, so if you try and print the product of two Rationals, you will get an error! Here we 
define how to print out a rational (from the '<<')    
*/
ostream& operator<<(ostream& stream, const Rational& rational) {
	int num = rational.getNumerator();
	int den = rational.getDenominator();
	stream << num << "/" << den;
	return stream;
}

// TODO:
ostream& operator>>(ostream& stream, const Rational& rational) {
	return stream;
}

/*
		OTHER FUNCTIONS
*/

void Rational::reduceFraction() {
	// Find greatest common factor (GCF) between numerator and denominator, divide
	int toDivide = min(numerator_, denominator_);
	int GCF = 0;

	for (int i = 2; i < toDivide; i++) {
		if ((numerator_%i == 0) && (denominator_%i == 0)) {
			GCF = i;
		}
	}
	if (GCF) {
		numerator_ /= GCF;
		denominator_ /= GCF;
	}

}


bool Rational::set_value(int num, int den) {
	numerator_ = num;
	denominator_ = den;
	return true;
}