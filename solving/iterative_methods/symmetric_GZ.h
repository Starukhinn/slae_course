#pragma once
#include <iostream>
#include <vector>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::vector;
using std::swap;

void SwapVectors(vector<double>& vector1, vector<double>& vector2);

vector<double> MakeFirstIterationOfSymmetricGZ(const CSRMatrix& a_matrix, const vector<double>& x_0,
                                               const vector<double>& b);

pair<vector<double>, int> SymmetricGZ(const CSRMatrix& a_matrix, const vector<double>& x_0, const vector<double>& b,
                                      const double& rho, const double& tolerance);