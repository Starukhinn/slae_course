#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::istream;

class NumbersColumn {
public:
    NumbersColumn(const int &number_elements);

    NumbersColumn(const vector<float> &column);

    void ChangeElement(const int &number_element, const float &element);

    float GiveElement(const int number_element) const;

    friend bool operator==(const NumbersColumn &first_column, const NumbersColumn &second_column);

    size_t GiveSize() const;
private:
    vector<float> numbers_;

    void ReplaceElement(const int &number_element, const float &element);
};