#pragma once
#include <iostream>
#include <vector>
#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"
#include <cmath>

using std::vector;

vector<float> MPI(const CSRMatrix &a_matrix, const vector<float> &x_0, const vector<float> &b, float tolerance, float tau);


