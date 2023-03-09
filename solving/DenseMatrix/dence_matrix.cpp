#include "dence_matrix.h"

Matrix::Matrix() {
    matrix_ = {};
    number_columns_ = 0;
}
Matrix::Matrix(const vector<double>& elements, const int& number_columns) {
    number_columns_ = number_columns;
    matrix_ = elements;
}

double Matrix::FindElement(const int& number_row, const int& number_column) const {
    int number_element_in_list = number_columns_ * number_row + number_column;
    return matrix_[number_element_in_list];
}
double Matrix::GiveElement(const int& number_row, const int& number_column) const {
    return FindElement(number_row, number_column);
}

vector<double> Matrix::GiveMatrix() const {
    return matrix_;
}
int Matrix::GiveNumberColumns() const {
    return number_columns_;
}
void Matrix::ChangeNestedColumn(const vector<double>& column, const int& number_column) {
    int number_elements_above_column_in_matrix = matrix_.size() / number_columns_ - column.size();
    for (int number_column_element = 0; number_column_element < column.size();
         ++number_column_element) {
        int number_matrix_element_fro_swapping =
            number_column +
            (number_column_element + number_elements_above_column_in_matrix) * number_columns_;
        matrix_[number_matrix_element_fro_swapping] = column[number_column_element];
    }
}
void Matrix::ModifyNestedColumn(const vector<double>& column, const int& number_column) {
    ChangeNestedColumn(column, number_column);
}

vector<double> Matrix::SelectsNestedColumn(const int& number_first_element,
                                          const int& number_column) {
    vector<double> nested_column;
    nested_column.reserve(matrix_.size() / number_columns_ - number_first_element);
    int number_matrix_rows = matrix_.size() / number_columns_;
    int number_first_column_element_in_matrix =
        number_column + number_first_element * number_columns_;
    for (int matrix_number_element = number_first_column_element_in_matrix;
         matrix_number_element < number_matrix_rows; matrix_number_element += number_columns_) {
        nested_column.push_back(matrix_[matrix_number_element]);
    }
    return nested_column;
}

vector<double> Matrix::GiveNestedColumn(const int& first_element, const int& number_column) {
    return SelectsNestedColumn(first_element, number_column);
}

vector<double> Matrix::SelectsNestedRow(const int& first_element, const int& number_row) {
    vector<double> nested_row;
    nested_row.reserve(number_columns_ - first_element);
    int number_matrix_element = number_row * number_columns_ + first_element;
    for (number_matrix_element; number_matrix_element < number_columns_; ++number_matrix_element) {
        nested_row.push_back(matrix_[number_matrix_element]);
    }
    return nested_row;
}

vector<double> Matrix::GiveNestedRow(const int& first_element, const int& number_row) {
    return SelectsNestedRow(first_element, number_row);
}

void Matrix::ChangeNestedRow(const vector<double>& row, const int& number_row) {
    int number_elements_left_of_row = matrix_.size() / number_columns_ - row.size();
    for (int number_row_element = 0; number_row_element < row.size(); ++number_row_element) {
        int number_matrix_element_for_swapping =
            (number_row_element + number_elements_left_of_row) +
            matrix_.size() / number_columns_ * number_row;
        matrix_[number_matrix_element_for_swapping] = row[number_row_element];
    }
}

void Matrix::ModifyNestedRow(const vector<double>& row, const int& number_row) {
    ChangeNestedRow(row, number_row);
}

Matrix operator*(const double& number, const Matrix& matrix) {
    vector<double> new_matrix;
    new_matrix.reserve(matrix.GiveMatrix().size());
    for (auto element : matrix.GiveMatrix()) {
        element *= number;
        new_matrix.push_back(element);
    }
    return {new_matrix, matrix.GiveNumberColumns()};
}

Matrix operator*(const Matrix& matrix, vector<double>& numbers) {
    vector<double> new_matrix;
    new_matrix.reserve(matrix.GiveMatrix().size());
    int number_rows = matrix.GiveMatrix().size() / matrix.GiveNumberColumns();
    for (int number_row = 0; number_row < number_rows; ++number_row) {
        float new_element = 0;
        for (int number_column = 0; number_column < matrix.GiveNumberColumns(); ++number_column) {
            double matrix_element = matrix.GiveElement(number_row, number_column);
            double column_element = numbers[number_column];
            new_element += matrix_element * column_element;
        }
        new_matrix.push_back(new_element);
    }
    return {new_matrix, 1};
}

Matrix operator-(const Matrix& first_matrix, const Matrix& second_matrix) {
    vector<double> new_matrix;
    new_matrix.reserve(first_matrix.GiveMatrix().size());
    for (int number_matrix_element = 0; number_matrix_element < first_matrix.GiveMatrix().size();
         ++number_matrix_element) {
        new_matrix.push_back(first_matrix.GiveMatrix()[number_matrix_element] -
                             second_matrix.GiveMatrix()[number_matrix_element]);
    }
    return {new_matrix, first_matrix.GiveNumberColumns()};
}