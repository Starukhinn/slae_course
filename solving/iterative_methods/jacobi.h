#pragma once
#include <iostream>
#include <vector>
#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include <cmath>

vector<double> Jacobi(const CSRMatrix &a_matrix, const vector<double> &x_0, const vector<double> &b, const double &tolerance);
