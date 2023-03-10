#pragma once

#include <iostream>
#include <vector>

using std::vector;

class Matrix {
public:
    Matrix();
    Matrix(const vector<double> &elements, const int &number_columns);
    double GiveElement(const int &number_row, const int &number_column) const;
    vector<double> GiveMatrix() const;
    int GiveNumberColumns() const;
    void ModifyNestedColumn(const vector<double> &column, const int &number_column);
    void ModifyNestedRow(const vector<double> &row, const int &number_row);
    vector<double> GiveNestedColumn(const int &first_element, const int &number_column);
    vector<double> GiveNestedRow(const int &first_element, const int &number_row);

private:
    vector<double> matrix_;
    int number_columns_;
    double FindElement(const int &number_row, const int &number_column) const;
    void ChangeNestedColumn(const vector<double> &column, const int &number_column);
    void ChangeNestedRow(const vector<double> &row, const int &number_row);
    vector<double> SelectsNestedColumn(const int &first_element, const int &number_column);
    vector<double> SelectsNestedRow(const int &first_element, const int &number_row);
};

Matrix operator*(const double &number, const Matrix &matrix);
Matrix operator*(const Matrix &matrix, vector<double> &numbers);
Matrix operator*(const Matrix &matrix, vector<double> &numbers);
Matrix operator-(const Matrix &first_matrix, const Matrix &second_matrix);