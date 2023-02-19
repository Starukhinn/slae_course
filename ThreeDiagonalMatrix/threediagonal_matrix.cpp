#include "threediagonal_matrix.h"

DiagonalElementsLine::DiagonalElementsLine() {
    first_element_ = 0.0;
    second_element_ = 0.0;
    third_element_ = 0.0;
}

DiagonalElementsLine::DiagonalElementsLine(const double &first_element, const double &second_element,
                                           const double &third_element) {
    first_element_ = first_element;
    second_element_ = second_element;
    third_element_ = third_element;
}

double DiagonalElementsLine::GiveElement(const int &number_element) const {
    return GiveElementByNumber(number_element);
}


double DiagonalElementsLine::GiveElementByNumber(const int &number_element) const {
    if (number_element == 0) {
        return first_element_;
    } else if (number_element == 1) {
        return second_element_;
    } else if (number_element == 2) {
        return third_element_;
    } else {
        throw number_element;
    }
}


bool operator==(const DiagonalElementsLine &first_element, const DiagonalElementsLine &second_element) {
    if (first_element.GiveElement(0) == second_element.GiveElement(0) and
        first_element.GiveElement(1) == second_element.GiveElement(1) and
        first_element.GiveElement(2) == second_element.GiveElement(2)) {
        return true;
    }
    return false;
}


ThreeDiagonalMatrix::ThreeDiagonalMatrix() {
    diagonal_elements_ = {};
}

ThreeDiagonalMatrix::ThreeDiagonalMatrix(const size_t &number_rows) {
    diagonal_elements_ = {};
    diagonal_elements_.resize(number_rows, {});
}

ThreeDiagonalMatrix::ThreeDiagonalMatrix(const vector<DiagonalElementsLine> &diagonal_elements) {
    diagonal_elements_ = diagonal_elements;
}

void ThreeDiagonalMatrix::Display() const {
    PrintMatrix();
}


void ThreeDiagonalMatrix::ReplaceRow(const size_t &number_line, const DiagonalElementsLine &new_line) {
    diagonal_elements_[number_line] = new_line;
}

void ThreeDiagonalMatrix::PrintMatrix() const {
    for (size_t number_line = 0; number_line < diagonal_elements_.size(); ++number_line) {
        size_t number_nulls_before_diagonal_elements_line;
        size_t number_nulls_after_diagonal_elements_line;
        if (number_line == 0) {
            number_nulls_before_diagonal_elements_line = 0;
            number_nulls_after_diagonal_elements_line = diagonal_elements_.size() - 3;
        } else if (number_line == diagonal_elements_.size() - 1) {
            number_nulls_before_diagonal_elements_line = number_line - 2;
            number_nulls_after_diagonal_elements_line = 0;
        } else {
            number_nulls_before_diagonal_elements_line = number_line - 1;
            number_nulls_after_diagonal_elements_line = diagonal_elements_.size() - 3 -
                                                        number_nulls_before_diagonal_elements_line;
        }
        for (size_t number_element_line = 0;
             number_element_line < number_nulls_before_diagonal_elements_line;
             ++number_element_line) {
            cout << 0 << ' ';
        }
        cout << diagonal_elements_[number_line].GiveElement(0) << ' '
             << diagonal_elements_[number_line].GiveElement(1) << ' ' <<
             diagonal_elements_[number_line].GiveElement(2) << ' ';
        for (size_t number_element_line = 0;
             number_element_line < number_nulls_after_diagonal_elements_line;
             ++number_element_line) {
            cout << 0 << ' ';
        }
        cout << '\n';
    }
}


double ThreeDiagonalMatrix::GiveElement(const size_t &number_line, const size_t &number_element_amount_3) const {
    return diagonal_elements_[number_line].GiveElement(number_element_amount_3);

}

size_t ThreeDiagonalMatrix::GetSize() const {
    return diagonal_elements_.size();
}


vector<DiagonalElementsLine> ThreeDiagonalMatrix::GiveMatrix() const {
    return diagonal_elements_;
}


//bool operator==(const ThreeDiagonalMatrix &first_matrix, const ThreeDiagonalMatrix &second_matrix) {
//    if (first_matrix.GiveMatrix() == second_matrix.GiveMatrix()) {
//        return true;
//    }
//    return false;
//}

ThreeDiagonalMatrix MakeMatrix(const int &number_rows) {
    ThreeDiagonalMatrix matrix(number_rows);
    bool row_is_first_in_matrix = true;
    bool row_is_last_in_matrix = false;
    int number_row = 0;
    while (number_row < number_rows) {
        double first_element;
        double second_element;
        double third_element;
        if (row_is_first_in_matrix) {
            row_is_first_in_matrix = false;
            third_element = 0;
            cin >> first_element >> second_element;

        } else if (row_is_last_in_matrix) {
            first_element = 0;
            cin >> second_element >> third_element;
        } else {
            cin >> first_element >> second_element >> third_element;
            if (number_row == number_rows - 2) {
                row_is_last_in_matrix = true;
            }
        }
        matrix.ReplaceRow(number_row, {first_element, second_element, third_element});
        ++number_row;
    }
    return matrix;
}
