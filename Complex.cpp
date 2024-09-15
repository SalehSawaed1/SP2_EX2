#include "Complex.hpp"  // Include the Complex class header

// Constructor initializing real and imaginary parts
Complex::Complex(double r, double i) : re(r), im(i) {}

// Return the real part of the complex number
double Complex::get_re() const {
    return re;
}

// Return the imaginary part of the complex number
double Complex::get_im() const {
    return im;
}

// Equality operator to check if both real and imaginary parts are equal
bool Complex::operator==(const Complex &other) const {
    return re == other.re && im == other.im;
}

// Inequality operator to check if real or imaginary parts are unequal
bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

// Less-than operator to compare real parts, or imaginary parts if real parts are equal
bool Complex::operator<(const Complex &other) const {
    if (re == other.re) {
        return im < other.im;
    }
    return re < other.re;
}

// Greater-than operator to compare real parts, or imaginary parts if real parts are equal
bool Complex::operator>(const Complex &other) const {
    if (re == other.re) {
        return im > other.im;
    }
    return re > other.re;
}

// Output the complex number in a readable format
std::ostream& operator<<(std::ostream &os, const Complex &c) {
    os << " " << c.re << " + " << c.im << "i ";
    return os;
}

