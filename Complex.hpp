#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>  // Include iostream for output operations

class Complex {
public:
    Complex(double r = 0, double i = 0);  // Constructor to initialize real and imaginary parts

    bool operator==(const Complex &other) const;  // Equality operator to compare two complex numbers

    bool operator!=(const Complex &other) const;  // Inequality operator to compare two complex numbers

    bool operator<(const Complex &other) const;  // Less-than operator to compare two complex numbers

    bool operator>(const Complex &other) const;  // Greater-than operator to compare two complex numbers

    friend std::ostream& operator<<(std::ostream &os, const Complex &c);  // Output stream operator to print a complex number

    double get_re() const;  // Return the real part of the complex number

    double get_im() const;  // Return the imaginary part of the complex number

private:
    double re;  // Real part of the complex number
    double im;  // Imaginary part of the complex number
};

#endif // COMPLEX_HPP
