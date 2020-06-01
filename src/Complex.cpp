/*
 * Complex.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: yunus
 */

#include <iostream>
#include <fstream>
#include "Complex.h"
using namespace std;

ostream& operator << (ostream &out, const Complex &c) {
  if (c.get_imaginary() < 0) {
    out << c.get_real() << c.get_imaginary() << 'i'; // the negative sign will already be there
  }
  else {
    out << c.get_real() << '+' << c.get_imaginary() << 'i';
  }
  return out;
}
istream& operator >> (istream &in, Complex &c) {
  char a, a1;
  in >> c.real >> a >> c.imaginary >> a1;
  // I made a and a1 so that the '+' or '-' can be stored in a variable
  // this is so that we can check if c.imaginary is meant to be negative

  // what happens if c.imaginary is meant to be negative (i.e. if it's a-bi instead of a+bi)?
  // we read in the '-', so we only have the positive number
  // easy: make the positive number negative
  if (a == '-')
    c.imaginary *= -1;

  return in;
}
Complex operator + (const Complex &c1, const Complex &c2) {
  Complex c3;
  c3.real = c1.real + c2.real;
  c3.imaginary = c1.imaginary + c2.imaginary;
  return c3;
}
Complex::Complex() {
  real = 0;
  imaginary = 0;
}
Complex::Complex(double r, double i) {
  real = r;
  imaginary = i;
}
Complex::Complex(const Complex &c) {
  real = c.real;
  imaginary = c.imaginary;
}
double Complex::operator + (int i) {
  return (real + i);
}
void Complex::set_real(double REAL) {
  real = REAL;
}
void Complex::set_imaginary(double IMAGINARY) {
  imaginary = IMAGINARY;
}
double Complex::get_real() const {
  return real;
}
double Complex::get_imaginary() const {
  return imaginary;
}
