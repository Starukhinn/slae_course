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

    NumbersColumn(const vector<double> &column);

    void Display() const;

    void ChangeElement(const int &number_element, const double &element);

    double GiveElement(const int number_element) const;

    vector<double> GiveColumn() const;

private:
    vector<double> numbers_;

    void PrintNumbers() const;

    void ReplaceElement(const int &number_element, const double &element);
};

bool operator==(const NumbersColumn &first_column, const NumbersColumn &second_column);

NumbersColumn MakeNumbersColumn(const int &column_size);