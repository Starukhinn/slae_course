#include "csr_matrix.h"


CSRMatrix::CSRMatrix(const map<Indexes,double> &matrix){
    for (auto const &element: matrix){
        values_.push_back(element.second);
        columns_indexes_.push_back(element.first.number_column);
    }
    number_non_0_rows_elements_ = CountNonZeroRowElements(matrix);
}

vector<int> CSRMatrix::CountNonZeroRowElements(const map<Indexes, double> &matrix){
    vector<int> number_non_0_rows_elements;
    int number_non_0_elements = 0;
    for (auto matrix_element = matrix.begin(); matrix_element != matrix.end(); ++matrix_element) {
        if (matrix_element == matrix.begin() or prev(matrix_element, 1)->first.number_row != matrix_element->first.number_row){
            number_non_0_rows_elements.push_back(number_non_0_elements);
        }
        else{
            ++number_non_0_elements;
        }
    }
}

float CSRMatrix::GiveElement(const size_t &number_row, const size_t &number_column) const {
    int number_elements_before_row = number_non_0_rows_elements_[number_row];
    int number_elements_after_row = number_non_0_rows_elements_[number_row + 1];
    int number_row_elements = number_non_0_rows_elements_[number_row + 1] - number_non_0_rows_elements_[number_row];
    for(int number_no_0_element = number_elements_before_row)
}

