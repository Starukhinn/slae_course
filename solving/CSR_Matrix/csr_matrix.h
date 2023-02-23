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

struct CSRMatrixData{
    vector<float>  values;
    vector<size_t> columns_indexes;
    vector<int> number_rows_non_0_elements;
};

bool operator==(const CSRMatrixData &first_data, const CSRMatrixData &second_data);

bool operator<(const Indexes &first_indexes, const Indexes &second_indexes);

class CSRMatrix {
public:
    CSRMatrix(const map<Indexes,float> &matrix);
    float GiveElement(const size_t &number_row, const size_t &number_column) const;
    vector<float> MultiplyByColumn(const vector<float> &column);
    CSRMatrixData GiveInformation() const;
    friend bool operator==(const CSRMatrix &first_matrix, const CSRMatrix &second_matrix);

private:
    vector<float>  values_;
    vector<size_t> columns_indexes_;
    vector<int> number_rows_non_0_elements_;

    vector<int>CountNonZeroRowElements(const map<Indexes,float> &matrix);
    float FindElement(const size_t &number_row, const size_t &number_column) const;

    vector<float> MultiplicationColumn(const vector<float> &column);

};


