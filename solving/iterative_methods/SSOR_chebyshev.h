#pragma once

#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::swap;
using std::vector;

vector<double> SSORIterationChebyshev(const CSRMatrix &a_matrix, const vector<double> &x_0,
                             const vector<double> &b, double omega);

void SwapVectorsChebyshev(vector<double> &vector1, vector<double> &vector2);

pair<vector<double>, int> SSORChebyshev(const CSRMatrix matrix_a, const vector<double> &x_0,
                               const vector<double> &b, const double &omega, const double &rho,
                               const double &tolerance);