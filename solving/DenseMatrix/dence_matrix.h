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
    void ModifyNestedColumn(const vector<float> &column, const int &number_column);
    void ModifyNestedRow(const vector<float> &row, const int &number_row);
    vector<float> GiveNestedColumn(const int &first_element, const int &number_column);
    vector<float> GiveNestedRow(const int& first_element, const int& number_row);
private:
    vector<float> matrix_;
    int number_columns_;
    float FindElement(const int &number_row, const int &number_column) const;
    void ChangeNestedColumn(const vector<float> &column, const int &number_column);
    void ChangeNestedRow(const vector<float> &row, const int &number_row);
    vector<float> SelectsNestedColumn(const int &first_element, const int &number_column);
    vector<float> SelectsNestedRow(const int &first_element, const int &number_row);
};

Matrix operator*(const float &number, const Matrix &matrix);
Matrix operator*(const Matrix &matrix, vector<float> &numbers);
Matrix operator*(const Matrix &matrix, vector<float> &numbers);
Matrix operator-(const Matrix &first_matrix, const Matrix &second_matrix);