/*
 * Complex.h
 *
 *  Created on: Sep 8, 2019
 *      Author: yunus
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <fstream>
using namespace std;

class Complex {
  // global block
  friend ostream& operator << (ostream &out, const Complex &c);
  friend istream& operator >> (istream &in, Complex &c);
  friend Complex operator + (const Complex &c1, const Complex &c2);
public:
  Complex();
  // default constructor
  Complex(double r, double i);
  // regular constructor, real = r and imaginary = i
  Complex(const Complex &c);
  // copy constructor

  // operators
  double operator + (int i);
  Complex operator - (const Complex &c) {
    Complex c1;
    c1.real = real - c.real;
    c1.imaginary = imaginary - c.imaginary;
    return c1;
  }
  Complex operator - (int i) {
    Complex r;
    r.real = real - i;
    return r;
  }
  Complex& operator = (const Complex &c) {
    if (this == &c)
      return *this;
    real = c.real;
    imaginary = c.imaginary;
    return *this;
  }

  // setter and getter functions
  // bc for some reason, Eclipse won't let me use private data members in friend functions
  void set_real(double REAL), set_imaginary(double IMAGINARY);
  double get_real() const, get_imaginary() const;
private:
  double real, imaginary;
};

#endif /* COMPLEX_H_ */
