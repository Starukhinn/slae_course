#pragma once

#include <iostream>
#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::vector;

pair<vector<double>, int> FastDescent(const CSRMatrix &matrix_a, const vector<double> &x_0,
                                      const vector<double> &b, const double &tolerance);