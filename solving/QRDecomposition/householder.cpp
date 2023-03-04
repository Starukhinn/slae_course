#include "householder.h"

#import <cmath>

VectorMatrix MakeBasisVector(const int &number_elements) {
    vector<float> basis_vector(0.0, number_elements);
    basis_vector[0] = 1.0;
    return {basis_vector};
}

VectorMatrix FindNormal(const VectorMatrix &matrix_column) {
    VectorMatrix basis_vector = MakeBasisVector(matrix_column.GiveSize());
    bool first_coordinate_more_null = matrix_column.GiveElement(0) > 0.0;
    VectorMatrix matrix_column_normal;
    float matrix_column_length = sqrt(matrix_column * matrix_column);
    if (first_coordinate_more_null) {
        matrix_column_normal = matrix_column + matrix_column_length * basis_vector;
    } else {
        matrix_column_normal = matrix_column - matrix_column_length * basis_vector;
    }
    return matrix_column_normal;
}

Matrix MultiplyColumnRow(const VectorMatrix &column, const VectorMatrix &row) {
    vector<float> matrix;
    matrix.reserve(row.GiveSize() * column.GiveSize());
    for (int number_column_element = 0; number_column_element < column.GiveSize();
         ++number_column_element) {
        for (int number_row_element = 0; number_row_element < row.GiveSize();
             ++number_row_element) {
            matrix.push_back(column.GiveElement(number_column_element) *
                             row.GiveElement(number_row_element));
        }
    }
    return {matrix, row.GiveSize()};
}

Matrix MakeTransformationMatrix(const VectorMatrix &normal) {
    int size_transformation_matrix = normal.GiveSize();
    vector<float> unit_matrix(0, size_transformation_matrix);
    for (int number_row = 0; number_row < size_transformation_matrix; ++number_row) {
        unit_matrix[number_row * size_transformation_matrix + number_row] = 1;
    }
    Matrix transformation_matrix(unit_matrix, size_transformation_matrix);
    Matrix tensor_product_normal = MultiplyColumnRow(normal, normal);
    transformation_matrix = transformation_matrix - (2 / (normal * normal)) * tensor_product_normal;
    return transformation_matrix;
}

VectorMatrix ConvertsMatrixColumnOrRow(const VectorMatrix &matrix_column,
                                       const VectorMatrix &normal, const float &denominator) {
    float numerator = matrix_column * normal;
    VectorMatrix converted_column = matrix_column - 2.0 * numerator / denominator * normal;
    return converted_column;
}

void TransformUpperDiagonalMatrix(Matrix &matrix, const int &number_transformation,
                                  const VectorMatrix &normal, const float &denominator) {
    for (int number_column = number_transformation; number_column < matrix.GiveNumberColumns();
         ++number_column) {
        VectorMatrix converted_column =
            matrix.GiveNestedColumn(number_transformation, number_column);
        converted_column = ConvertsMatrixColumnOrRow(converted_column, normal, denominator);
        matrix.ModifyNestedColumn(converted_column.GiveVector(), number_column);
    }
}

void TransformOrthogonalMatrix(Matrix &matrix, const int &number_transformation,
                               const VectorMatrix &normal, const float &denominator) {
    for (int number_row = 0; number_row < matrix.GiveNumberColumns(); ++number_row) {
        VectorMatrix converted_row = matrix.GiveNestedRow(0, number_row);
        converted_row = ConvertsMatrixColumnOrRow(converted_row, normal, denominator);
        matrix.ModifyNestedRow(converted_row.GiveVector(), number_row);
    }
}

QRDecomposition HouseholderAlgorithm(const Matrix &original_matrix) {
    Matrix upper_diagonal_matrix = original_matrix;
    VectorMatrix matrix_column = {upper_diagonal_matrix.GiveNestedColumn(0, 0)};
    VectorMatrix normal = FindNormal(matrix_column);
    Matrix transformation_matrix = MakeTransformationMatrix(normal);
    for (int number_transformation = 0; number_transformation < original_matrix.GiveNumberColumns();
         ++number_transformation) {
        matrix_column = {
            upper_diagonal_matrix.GiveNestedColumn(number_transformation, number_transformation)};
        normal = FindNormal(matrix_column);
        float denominator = normal * normal;
        TransformUpperDiagonalMatrix(upper_diagonal_matrix, number_transformation, normal,
                                     denominator);
        TransformOrthogonalMatrix(transformation_matrix, number_transformation, normal,
                                  denominator);
    }
    return {transformation_matrix, upper_diagonal_matrix};
}
