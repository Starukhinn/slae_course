#pragma once
#include "../DenseMatrix/dence_matrix.h"
#include "../Vector/vector_matrix.h"
#include <iostream>

vector<float>MakeBasisVector(const int &number_basis_column, const int &number_elements);

vector<float> FindNormal(const vector<float> &matrix_column, const int &number_column,  const int &number_elements);




