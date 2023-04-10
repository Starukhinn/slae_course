#pragma one
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "../../solving/CSR_Matrix/csr_matrix.h"
#include "../../solving/Vector/vector_matrix.h"

using std::pair;
using std::vector;

pair<vector<double>, int> MpiFast(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                  const vector<double> &b, const double &tolerance,
                                  const int &r_parameter, const double &min_lambda,
                                  const double &max_lambda);

vector<double> MakePolynomialRoots(const double &sin_a, const double &cos_a, double &sin_b,
                                   const size_t &number_polynomial_roots);

vector<size_t> MakeIndexSequence(const size_t &number_polynomial_roots, const int &r_parameter);

pair<vector<double>, int> FastMPIAlgorithm(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                           const vector<double> &b, const double &tolerance,
                                           const size_t &number_polynomial_roots,
                                           const vector<double> &polynomial_roots,
                                           const vector<size_t> &indexes);
