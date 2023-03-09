#pragma once
#include <iostream>
#include <vector>
#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include <cmath>

using std::vector;
using std::pair;

pair<vector<double>, int> MPI(const CSRMatrix &a_matrix, const vector<double> &x_0, const vector<double> &b, const double &tolerance, const double &tau);


