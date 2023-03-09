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

bool operator<(const Indexes &first_indexes, const Indexes &second_indexes);

class CSRMatrix {
public:
    CSRMatrix(const map<Indexes,double> &matrix, const int &number_rows, const int &number_column);
    double GiveElement(const size_t &number_row, const size_t &number_column) const;
    friend bool operator==(const CSRMatrix &first_matrix, const CSRMatrix &second_matrix);
    vector<double> GiveValues() const;
    vector<size_t> GiveColumnsIndexes() const;
    vector<int> GiveNumberRowsNon0Elements() const;
    int GiveNumberColumns() const;
    int GiveNumberRows() const;
private:
    vector<double>  values_;
    vector<size_t> columns_indexes_;
    vector<int> number_rows_non_0_elements_;
    int number_columns_;
    int number_rows_;

    vector<int>CountNonZeroRowElements(const map<Indexes,double> &matrix);
    double FindElement(const size_t &number_row, const size_t &number_column) const;
};

vector<double> operator*(const CSRMatrix &matrix, const vector<double> &column);


