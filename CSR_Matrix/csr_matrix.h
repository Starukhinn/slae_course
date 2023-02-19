#pragma once
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::prev;

struct Indexes{
    size_t number_row;
    size_t number_column;
};

class CSRMatrix {
public:
    CSRMatrix(const map<Indexes,double> &matrix);
    float GiveElement(const size_t &number_row, const size_t &number_column) const;
    vector<float> MultiplyByColumn(const vector<float> &column);
private:
    vector<double>  values_;
    vector<size_t> columns_indexes_;
    vector<int> number_rows_non_0_elements_;

    vector<int>CountNonZeroRowElements(const map<Indexes,double> &matrix);
    float FindElement(const size_t &number_row, const size_t &number_column) const;

    vector<float> MultiplicationColumn(const vector<float> &column);

};


