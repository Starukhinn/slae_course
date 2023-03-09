#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<float> operator+(const vector<float> &first_vector, const vector<float> &second_vector);

vector<float> operator-(const vector<float> &first_vector, const vector<float> &second_vector);

float operator*(const vector<float> &first_vector, const vector<float> &second_vector);

vector<float> operator*(const float &number, const vector<float> &second_vector);

vector<float> operator/(const vector<float> &numbers, const float &number);

float GiveVectorLength(const vector<float> &vector);