#pragma once

#include <iostream>
#include <vector>
using std::vector;

class VectorMatrix{
public:
    VectorMatrix();
    VectorMatrix(const vector<float> &elements);
    vector<float> GiveVector()const;
    float GiveElement(const int &number_element) const;
private:
    vector<float> numbers_;
};

VectorMatrix operator+(const VectorMatrix &first_vector, const VectorMatrix &second_vector);

VectorMatrix operator-(const VectorMatrix &first_vector, const VectorMatrix &second_vector);

float operator*(const VectorMatrix &first_vector, const VectorMatrix &second_vector);

VectorMatrix operator*(const float &number, const VectorMatrix &second_vector);
