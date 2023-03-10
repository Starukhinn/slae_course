#pragma once

#include <iostream>

#include "numbers_column.h"
#include "threediagonal_matrix.h"

struct AuxiliaryCoefficients {
    double p_coef;
    double q_coef;
};

NumbersColumn Progonka(const ThreeDiagonalMatrix &matrix, const NumbersColumn &free_members);

vector<AuxiliaryCoefficients> FindAuxiliaryCoefficients(const ThreeDiagonalMatrix &matrix,
                                                        const NumbersColumn &unknown_column);