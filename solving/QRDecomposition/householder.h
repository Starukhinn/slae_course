#pragma once
#include "../DenseMatrix/dence_matrix.h"
#include "../Vector/vector_matrix.h"
#include <iostream>

struct QRDecomposition{
    Matrix Q;
    Matrix R;
};

VectorMatrix MakeBasisVector(const int &number_basis_column, const int &number_elements);
VectorMatrix FindNormal(const vector<float> &matrix_column, const int &number_column,  const int &number_elements);
VectorMatrix ConvertsMatrixColumn(const VectorMatrix &matrix_column, const VectorMatrix &normal, const float &denominator);
Matrix MultiplyColumnRow(const VectorMatrix &column, const VectorMatrix &row);
Matrix MakeTransformationMatrix(const VectorMatrix &normal);
VectorMatrix ConvertsMatrixColumnOrRow(const VectorMatrix &matrix_column, const VectorMatrix &normal, const float &denominator);
void TransformUpperDiagonalMatrix(Matrix &matrix, const int &number_transformation, const VectorMatrix &normal, const float &denominator);
void TransformOrthogonalMatrix(Matrix &matrix, const int &number_transformation, const VectorMatrix &normal, const float &denominator);
QRDecomposition HouseholderAlgorithm (const Matrix &original_matrix);