#pragma once
#include "../DenseMatrix/dence_matrix.h"
#include "../Vector/vector_matrix.h"
#include <iostream>

struct QRDecomposition{
    Matrix Q;
    Matrix R;
};

vector<float> MakeBasisVector(const int &number_basis_column, const int &number_elements);
vector<float> FindNormal(const vector<float> &matrix_column, const int &number_column,  const int &number_elements);
vector<float> ConvertsMatrixColumn(const vector<float> &matrix_column, const vector<float> &normal, const float &denominator);
Matrix MultiplyColumnRow(const vector<float> &column, const vector<float> &row);
Matrix MakeTransformationMatrix(const vector<float> &normal);
vector<float> ConvertsMatrixColumnOrRow(const vector<float> &matrix_column, const vector<float> &normal, const float &denominator);
void TransformUpperDiagonalMatrix(Matrix &matrix, const int &number_transformation, const vector<float> &normal, const float &denominator);
void TransformOrthogonalMatrix(Matrix &matrix, const int &number_transformation, const vector<float> &normal, const float &denominator);
QRDecomposition HouseholderAlgorithm (const Matrix &original_matrix);