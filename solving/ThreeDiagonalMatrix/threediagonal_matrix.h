#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class DiagonalElementsLine {
public:
    DiagonalElementsLine();

    DiagonalElementsLine(const float &first_element, const float &second_element,
                         const float &third_element);

    double GiveElement(const int &number_element) const;

private:
    float first_element_;
    float second_element_;
    float third_element_;

    float GiveElementByNumber(const int &number_element) const;
};

bool operator==(const DiagonalElementsLine &first_element,
                const DiagonalElementsLine &second_element);

class ThreeDiagonalMatrix {
public:
    ThreeDiagonalMatrix();

    ThreeDiagonalMatrix(const vector<DiagonalElementsLine> &diagonal_elements);

    size_t GetSize() const;

    double GiveElement(const size_t &number_line, const size_t &number_element_amount_3) const;

    friend bool operator==(const ThreeDiagonalMatrix &first_matrix,
                           const ThreeDiagonalMatrix &second_matrix);

    vector<DiagonalElementsLine> GiveMatrix() const;

private:
    vector<DiagonalElementsLine> diagonal_elements_;
};
