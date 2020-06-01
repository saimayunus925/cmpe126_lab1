//============================================================================
// Name        : lab_1_main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Complex.h"
using namespace std;

void ReadComplexFileEOF(string file_name, Complex obj_arr[], const int size);
// the user will input the size of the object array, and it will be equated to a constant int, which will be passed in as size

int main() {
  int s;
  cout << "Enter the size of your array of complex numbers: " << endl;
  // in this case, it must be 7, but I am keeping it like this b/c I've heard bad things about 'hardcoding'
  cin >> s;
  const int SIZE = s; // a nifty trick I 'discovered' for when you want
  // a user-inputted array size but don't wanna use dynamic memory or vectors
  Complex ca[SIZE]; // the array of complex number objects

  ReadComplexFileEOF("complex.txt", ca, SIZE);

  ofstream fout;
  fout.open("complexObj.txt");
  if (fout.fail()) {
    cout << "Output file failed to open." << endl;
    exit(1);
  }

  Complex sum;
  for (int j = 0; j < SIZE; j++) {
    fout << ca[j] << endl;
    sum = sum + ca[j];
  }
  fout << "SUM: ";
  fout << sum << endl;
  fout.close();
}

void ReadComplexFileEOF(string file_name, Complex obj_arr[], const int size) {
  ifstream fin;
  fin.open(file_name.c_str());
  if (fin.fail()) {
    cout << "Input file failed to open." << endl;
    exit(1);
  }
  int i = 0;
  while (!fin.eof() && i < size) {
    fin >> obj_arr[i++];
  }
  fin.close();
}
