#pragma once

#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::vector;

pair<vector<double>, int> SteepestDescentIteration(const CSRMatrix &matrix_a,
                                                   const vector<double> &b,
                                                   const vector<double> &x0,
                                                   const double tolerance);