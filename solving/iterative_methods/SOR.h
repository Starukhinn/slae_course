#pragma once

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include <vector>

using std::vector;
using std::pair;

pair<vector<double>, int> SOR(const CSRMatrix &a_matrix, const vector<double> x_0,  const vector<double> b,
                              const double &tolerance,const double &omega);