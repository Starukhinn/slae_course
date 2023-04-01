#pragma once

#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::vector;

pair<vector<double>, int> SOR(const CSRMatrix &a_matrix, const vector<double> x_0,
                              const vector<double> b, const double &tolerance, const double &omega);