#include "dence_matrix.h"

Matrix::Matrix() {
    matrix_ = {};
    number_columns_ = 0;
}
Matrix::Matrix(const vector<float>& elements, const int &number_columns) {
    number_columns_ = number_columns;
    matrix_ = elements;
}

float Matrix::FindElement(const int& number_row, const int& number_column) const {
    int number_element_in_list = number_columns_ * number_row + number_column;
    return matrix_[number_element_in_list];
}
float Matrix::GiveElement(const int& number_row, const int& number_column) const {
    return FindElement(number_row, number_column);
}

vector<float> Matrix::GiveMatrix() const{
    return matrix_;
}
int Matrix::GiveNumberColumns() const {
    return number_columns_;
}

Matrix MultiplicationByNumber(const Matrix &matrix, const float& number) {
    vector<float> new_matrix;
    for(auto element: matrix.GiveMatrix()){
        element *= number;
        new_matrix.push_back(element);
    }
    return {new_matrix, matrix.GiveNumberColumns()};
}


Matrix MultiplicationByColumn(const Matrix &matrix, vector<float> &numbers){
    vector<float> new_matrix;
    int number_rows = matrix.GiveMatrix().size() / matrix.GiveNumberColumns();
    for (int number_row = 0; number_row < number_rows; ++number_row){
        float new_element = 0;
        for(int number_column = 0; number_column < matrix.GiveNumberColumns(); ++number_column){
            float matrix_element = matrix.GiveElement(number_row, number_column);
            float column_element = numbers[number_column];
            new_element += matrix_element * column_element;
        }
        new_matrix.push_back(new_element);
    }
    return {new_matrix, 1};
}
