#include "threediagonal_matrix.h"

DiagonalElementsLine::DiagonalElementsLine() {
    first_element_ = 0.0;
    second_element_ = 0.0;
    third_element_ = 0.0;
}

DiagonalElementsLine::DiagonalElementsLine(const float &first_element, const float &second_element,
                                           const float &third_element) {
    first_element_ = first_element;
    second_element_ = second_element;
    third_element_ = third_element;
}

double DiagonalElementsLine::GiveElement(const int &number_element) const {
    return GiveElementByNumber(number_element);
}

float DiagonalElementsLine::GiveElementByNumber(const int &number_element) const {
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

bool operator==(const DiagonalElementsLine &first_element,
                const DiagonalElementsLine &second_element) {
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

ThreeDiagonalMatrix::ThreeDiagonalMatrix(const vector<DiagonalElementsLine> &diagonal_elements) {
    diagonal_elements_ = diagonal_elements;
}

double ThreeDiagonalMatrix::GiveElement(const size_t &number_line,
                                        const size_t &number_element_amount_3) const {
    return diagonal_elements_[number_line].GiveElement(number_element_amount_3);
}

size_t ThreeDiagonalMatrix::GetSize() const {
    return diagonal_elements_.size();
}

vector<DiagonalElementsLine> ThreeDiagonalMatrix::GiveMatrix() const {
    return diagonal_elements_;
}

bool operator==(const ThreeDiagonalMatrix &first_matrix, const ThreeDiagonalMatrix &second_matrix) {
    if (first_matrix.GiveMatrix() == second_matrix.GiveMatrix()) {
        return true;
    }
    return false;
}
