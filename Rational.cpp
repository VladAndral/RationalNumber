#include "Rational.h"

using namespace std; // Needed for ostream

/*
		CONSTRUCTOR
*/

// If you initialize a Rational object w/ no params, this is the default loadout
// If you see this fraction, something probably went wrong
Rational::Rational() : numerator_(-98999), denominator_(-99999) { }

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
	int denominator = (denominator_*refToRatObj.denominator_);
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

Rational Rational::operator-(const Rational& refToRatObj) const {
	int numerator = (numerator_*refToRatObj.denominator_) - (refToRatObj.numerator_*denominator_);
	int denominator = (denominator_*refToRatObj.denominator_);
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
	int numerator = numerator_ * refToRatObj.denominator_;
	int denominator = denominator_ * refToRatObj.numerator_;
	Rational toRetrun(numerator, denominator);
	return toRetrun;
}

bool Rational::operator==(const Rational& refToRatObj) const {
	return (numerator_*refToRatObj.denominator_) == (refToRatObj.numerator_*denominator_);
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

istream& operator>>(istream& stream,  Rational& rational) {
	string fractionInput;
	stream >> fractionInput;

	string st_numerator;
	string st_denominator;
	bool reachedSlash = false;
	for (int i = 0; i < fractionInput.length(); i++) {
		if (fractionInput[i] == '/') {
			reachedSlash = true;
			continue;
		}
		if (reachedSlash) {
			st_denominator += fractionInput[i];
		} else {
			st_numerator += fractionInput[i];
		}
    }
	int numerator = stoi(st_numerator);
	int denominator = stoi(st_denominator);
	rational.numerator_ = numerator;
	rational.denominator_ = denominator;
	

	return stream;
}

/*
		OTHER FUNCTIONS
*/

void Rational::reduceFraction() {
	// Find greatest common factor (GCF) between numerator and denominator, divide
	int toDivide = min(numerator_, denominator_);
	int GCF = 0;

	for (int i = 2; i <= toDivide; i++) {
		if ((numerator_%i == 0) && (denominator_%i == 0)) { // If both numbers divide evenly into i (no remainder)
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