#include "numbers_column.h"

NumbersColumn::NumbersColumn(const int &number_elements) {
    numbers_ = {};
    numbers_.resize(number_elements, 0);
}

NumbersColumn::NumbersColumn(const vector<float> &column) {
    numbers_ = column;
}


void NumbersColumn::ChangeElement(const int &number_element, const float &element) {
    ReplaceElement(number_element, element);
}

void NumbersColumn::ReplaceElement(const int &number_element, const float &element) {
    numbers_[number_element] = element;
}

float NumbersColumn::GiveElement(const int number_element) const {
    return numbers_[number_element];
}

bool operator==(const NumbersColumn &first_column, const NumbersColumn &second_column) {
    if (first_column.numbers_ == second_column.numbers_) {
        return true;
    }
    return false;
}
size_t NumbersColumn::GiveSize() const {
    return numbers_.size();
}
