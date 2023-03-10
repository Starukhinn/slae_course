#pragma once
#include <cmath>
#include <iostream>
#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include "string"

using std::pair;
using std::string;
using std::vector;

pair<vector<double>, int> Jacobi(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                 const vector<double> &b, const double &tolerance,
                                 const string &file_path);
