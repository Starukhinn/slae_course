#pragma once

#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::vector;

std::vector<double> SteepestDescentIteration(const CSRMatrix &matrix_a,
                                               const std::vector<double> &b,
                                               const std::vector<double> &x0,
                                               const double tolerance);