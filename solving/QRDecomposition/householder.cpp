#include "householder.h"

#import <cmath>

vector<float> MakeBasisVector(const int &number_elements) {
    vector<float> basis_vector(0.0, number_elements);
    basis_vector[0] = 1.0;
    return basis_vector;
}

vector<float> FindNormal(const vector<float> &matrix_column) {
    vector<float> basis_vector = MakeBasisVector(matrix_column.size());
    bool first_coordinate_more_null = matrix_column[0] > 0.0;
    vector<float> matrix_column_normal;
    float matrix_column_length = sqrt(matrix_column * matrix_column);
    if (first_coordinate_more_null) {
        matrix_column_normal = matrix_column + matrix_column_length * basis_vector;
    } else {
        matrix_column_normal = matrix_column - matrix_column_length * basis_vector;
    }
    return matrix_column_normal;
}

Matrix MultiplyColumnRow(const vector<float> &column, const vector<float> &row) {
    vector<float> matrix;
    matrix.reserve(row.size() * column.size());
    for (int number_column_element = 0; number_column_element < column.size();
         ++number_column_element) {
        for (int number_row_element = 0; number_row_element < row.size();
             ++number_row_element) {
            matrix.push_back(column[number_column_element] *
                             row[number_row_element]);
        }
    }
    return {matrix, row.size()};
}

Matrix MakeTransformationMatrix(const vector<float> &normal) {
    int size_transformation_matrix = normal.size();
    vector<float> unit_matrix(0, size_transformation_matrix);
    for (int number_row = 0; number_row < size_transformation_matrix; ++number_row) {
        unit_matrix[number_row * size_transformation_matrix + number_row] = 1;
    }
    Matrix transformation_matrix(unit_matrix, size_transformation_matrix);
    Matrix tensor_product_normal = MultiplyColumnRow(normal, normal);
    transformation_matrix = transformation_matrix - (2 / (normal * normal)) * tensor_product_normal;
    return transformation_matrix;
}

vector<float> ConvertsMatrixColumnOrRow(const vector<float> &matrix_column,
                                       const vector<float> &normal, const float &denominator) {
    float numerator = matrix_column * normal;
    vector<float> converted_column = matrix_column - 2.0 * numerator / denominator * normal;
    return converted_column;
}

void TransformUpperDiagonalMatrix(Matrix &matrix, const int &number_transformation,
                                  const vector<float> &normal, const float &denominator) {
    for (int number_column = number_transformation; number_column < matrix.GiveNumberColumns();
         ++number_column) {
        vector<float> converted_column =
            matrix.GiveNestedColumn(number_transformation, number_column);
        converted_column = ConvertsMatrixColumnOrRow(converted_column, normal, denominator);
        matrix.ModifyNestedColumn(converted_column, number_column);
    }
}

void TransformOrthogonalMatrix(Matrix &matrix, const int &number_transformation,
                               const vector<float> &normal, const float &denominator) {
    for (int number_row = 0; number_row < matrix.GiveNumberColumns(); ++number_row) {
        vector<float> converted_row = matrix.GiveNestedRow(0, number_row);
        converted_row = ConvertsMatrixColumnOrRow(converted_row, normal, denominator);
        matrix.ModifyNestedRow(converted_row, number_row);
    }
}

QRDecomposition HouseholderAlgorithm(const Matrix &original_matrix) {
    Matrix upper_diagonal_matrix = original_matrix;
    vector<float> matrix_column = {upper_diagonal_matrix.GiveNestedColumn(0, 0)};
    vector<float> normal = FindNormal(matrix_column);
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
