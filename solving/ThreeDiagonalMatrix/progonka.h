#pragma once

#include <iostream>
#include "threediagonal_matrix.h"
#include "numbers_column.h"

struct AuxiliaryCoefficients {
    double p_coef;
    double q_coef;
};

NumbersColumn Progonka(const ThreeDiagonalMatrix &matrix, const NumbersColumn &free_members);

vector<AuxiliaryCoefficients>
FindAuxiliaryCoefficients(const ThreeDiagonalMatrix &matrix, const NumbersColumn &unknown_column);