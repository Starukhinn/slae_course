#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<double> operator+(const vector<double> &first_vector, const vector<double> &second_vector);

vector<double> operator-(const vector<double> &first_vector, const vector<double> &second_vector);

double operator*(const vector<double> &first_vector, const vector<double> &second_vector);

vector<double> operator*(const double &number, const vector<double> &second_vector);

vector<double> operator/(const vector<double> &numbers, const double &number);

double GiveVectorLength(const vector<double> &vector);