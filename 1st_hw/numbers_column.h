#ifndef SLAE_COURSE_NUMBERS_COLUMN_H
#define SLAE_COURSE_NUMBERS_COLUMN_H

#endif //SLAE_COURSE_NUMBERS_COLUMN_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::istream;

class NumbersColumn {
public:
    NumbersColumn(const int &number_elements);
    void Display() const;
    void ChangeElement(const int &number_element, const double &element);
    void operator=(const NumbersColumn& elements);
    double GiveElement(const int number_element) const;
    vector<double> GiveColumn() const;

private:
    vector<double> numbers_;

    void PrintNumbers() const;
    void ReplaceElement(const int &number_element, const double &element);
};

bool operator==(const NumbersColumn &first_column, const NumbersColumn &second_column);

NumbersColumn MakeNumbersColumn(const int& column_size);