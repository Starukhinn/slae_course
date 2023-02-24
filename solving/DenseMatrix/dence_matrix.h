#pragma once

#include <iostream>
#include <iostream>
#include <vector>

using std::vector;

class Matrix{
public:
    Matrix();
    Matrix(const vector<float> &elements, const int &number_columns);
    float GiveElement(const int &number_row, const int &number_column) const;
    vector<float> GiveMatrix() const;
    int GiveNumberColumns() const;
private:
    vector<float> matrix_;
    float FindElement(const int &number_row, const int &number_column) const;
    int number_columns_;
};

Matrix MultiplicationByNumber(const Matrix &matrix, const float &number);
Matrix MultiplicationByColumn(const Matrix &matrix, vector<float> &numbers);
