#pragma once
#include <iostream>
#include <vector>
#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include <cmath>

vector<float> Jacobi(const CSRMatrix &a_matrix, const vector<float> &x_0, const vector<float> &b, float tolerance);
