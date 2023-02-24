#include "householder.h"
#import <cmath>

vector<float> MakeBasisVector(const int &number_basis_column, const int &number_elements){
    vector<float> basis_vector(0, number_elements);
    basis_vector[number_basis_column] = 1;
    return basis_vector;
}

vector<float> FindNormal(const vector<float> &matrix_column, const int &number_column, const int &number_elements){
    vector<float> basis_vector = MakeBasisVector(number_column, number_elements);
    bool first_coordinate_more_null = matrix_column[0] > 0;
    VectorMatrix matrix_column_normal;
    float matrix_column_length = sqrt(VectorMatrix(matrix_column) * VectorMatrix(matrix_column));
    if (first_coordinate_more_null){
        matrix_column_normal = VectorMatrix(basis_vector) + matrix_column_length * VectorMatrix(basis_vector);
    }
    else{
        matrix_column_normal = VectorMatrix(basis_vector) + matrix_column_length * VectorMatrix(basis_vector);
    }
    return matrix_column_normal.GiveVector();
}


