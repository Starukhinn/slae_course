#pragma once

#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::cin;
using std::cout;

class DiagonalElementsLine {
public:
    DiagonalElementsLine();

    DiagonalElementsLine(const double &first_element, const double &second_element, const double &third_element);

    double GiveElement(const int &number_element) const;

private:
    double first_element_;
    double second_element_;
    double third_element_;

    double GiveElementByNumber(const int &number_element) const;
};

bool operator==(const DiagonalElementsLine &first_element, const DiagonalElementsLine &second_element);

class TriangleMatrix {
public:
    TriangleMatrix();

    TriangleMatrix(const size_t &number_rows);

    TriangleMatrix(const vector<DiagonalElementsLine> &diagonal_elements);

    void Display() const;

    size_t GetSize() const;

    double GiveElement(const size_t &number_line, const size_t &number_element_amount_3) const;

    void ReplaceRow(const size_t &number_line, const DiagonalElementsLine &new_line);


    vector<DiagonalElementsLine> GiveMatrix() const;

private:
    vector<DiagonalElementsLine> diagonal_elements_;

    void PrintMatrix() const;
};

bool operator==(const TriangleMatrix &first_matrix, const TriangleMatrix &second_matrix);

TriangleMatrix MakeMatrix(const int &number_rows);

