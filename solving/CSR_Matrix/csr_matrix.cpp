#include "csr_matrix.h"


CSRMatrix::CSRMatrix(const map<Indexes, double> &matrix) {
    for (auto const &element: matrix) {
        if (element.second == 0) {
            continue;
        }
        values_.push_back(element.second);
        columns_indexes_.push_back(element.first.number_column);
    }
    number_rows_non_0_elements_ = CountNonZeroRowElements(matrix);
}

vector<int> CSRMatrix::CountNonZeroRowElements(const map<Indexes, double> &matrix) {
    vector<int> number_non_0_rows_elements;
    int number_non_0_elements = 0;
    for (auto matrix_element = matrix.begin(); matrix_element != matrix.end(); ++matrix_element) {
        if (matrix_element == matrix.begin() or
            prev(matrix_element, 1)->first.number_row != matrix_element->first.number_row) {
            number_non_0_rows_elements.push_back(number_non_0_elements);
        } else {
            ++number_non_0_elements;
        }
    }
    return number_non_0_rows_elements;
}

float CSRMatrix::FindElement(const size_t &number_row, const size_t &number_column) const {
    int number_elements_before_row = number_rows_non_0_elements_[number_row];
    int number_elements_after_row = number_rows_non_0_elements_[number_row + 1];
    for (int number_non_0_element = number_elements_before_row;
         number_non_0_element < number_elements_after_row; ++number_non_0_element) {
        if (columns_indexes_[number_non_0_element] == number_column) {
            return values_[number_non_0_element];
        }
    }
    return 0;
}

float CSRMatrix::GiveElement(const size_t &number_row, const size_t &number_column) const {
    return FindElement(number_row, number_column);
}

vector<float> CSRMatrix::MultiplicationColumn(const vector<float> &column) {
    vector<float> result_column;
    for (size_t number_row_in_matrix = 0; number_row_in_matrix < number_rows_non_0_elements_.size();
         ++number_row_in_matrix) {
        int number_elements_before_row = number_rows_non_0_elements_[number_row_in_matrix];
        int number_elements_after_row = number_rows_non_0_elements_[number_row_in_matrix + 1];
        float result_column_element = 0;
        for (int number_non_0_element = number_elements_before_row; number_non_0_element < number_elements_after_row;
             ++number_non_0_element) {
            size_t column_index_of_element = columns_indexes_[number_non_0_element];
            result_column_element += values_[number_non_0_element] * column[column_index_of_element];
        }
        result_column.push_back(result_column_element);
    }
    return result_column;
}

vector<float> CSRMatrix::MultiplyByColumn(const vector<float> &column) {
    return MultiplicationColumn(column);
}

CSRMatrixData CSRMatrix::GiveInformation() const {
    return {values_, columns_indexes_, number_rows_non_0_elements_};
}

bool operator==(const CSRMatrix &first_matrix, const CSRMatrix &second_matrix) {
    if (first_matrix.values_ == second_matrix.values_ and
    first_matrix.number_rows_non_0_elements_ == second_matrix.number_rows_non_0_elements_ and
    first_matrix.columns_indexes_ == second_matrix.columns_indexes_){
        return true;
    }
    return false;
}

bool operator<(const Indexes &first_indexes, const Indexes &second_indexes) {
    if (first_indexes.number_row < second_indexes.number_row) {
        return true;
    } else if (first_indexes.number_row == second_indexes.number_row) {
        if (first_indexes.number_column < second_indexes.number_column) {
            return true;
        }
        return false;
    }
    return false;
}





