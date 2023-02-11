#include "progonka.h"

vector<AuxiliaryCoefficients>
FindAuxiliaryCoefficients(const TriangleMatrix &matrix, const NumbersColumn &free_members) {
    vector<AuxiliaryCoefficients> array_of_auxiliary_coefficients = {};
    for (auto number_line = 0; number_line < matrix.GetSize() - 2; ++number_line) {
        double p_coef;
        double q_coef;
        if (number_line == 0) {
            p_coef = -1 * matrix.GiveElement(0, 0) /
                     matrix.GiveElement(0, 1);
            q_coef = free_members.GiveElement(0) /
                     matrix.GiveElement(0, 1);
        } else {
            p_coef = -1 * matrix.GiveElement(number_line, 2) /
                     (matrix.GiveElement(number_line, 0) * array_of_auxiliary_coefficients[number_line - 1].p_coef +
                      matrix.GiveElement(number_line, 1));
            q_coef = (free_members.GiveElement(number_line) - matrix.GiveElement(number_line, 0) *
                                                              array_of_auxiliary_coefficients[number_line - 1].q_coef) /
                     (matrix.GiveElement(number_line, 0) *
                      array_of_auxiliary_coefficients[number_line - 1].p_coef +
                      matrix.GiveElement(number_line, 1));
        }
        array_of_auxiliary_coefficients.push_back({p_coef, q_coef});
    }
    return array_of_auxiliary_coefficients;
}

NumbersColumn Progonka(const TriangleMatrix &matrix, const NumbersColumn &free_members) {
    NumbersColumn unknown_members(matrix.GetSize());
    vector<AuxiliaryCoefficients> array_of_auxiliary_coefficients = FindAuxiliaryCoefficients(matrix, free_members);
    for (int number_line = matrix.GetSize() - 1; number_line >= 0; --number_line) {
        double answer_member;
        if (number_line == matrix.GetSize() - 1) {
            answer_member = (free_members.GiveElement(number_line) -
                             matrix.GiveElement(number_line, 0) *
                             array_of_auxiliary_coefficients[number_line - 1].q_coef) /
                            (matrix.GiveElement(number_line, 0) *
                             array_of_auxiliary_coefficients[number_line - 1].p_coef +
                             matrix.GiveElement(number_line, 1));
        }
        else {
            answer_member = array_of_auxiliary_coefficients[number_line].p_coef * unknown_members.GiveElement(number_line + 1) +
                    array_of_auxiliary_coefficients[number_line].q_coef;
        }
        unknown_members.ChangeElement(number_line, answer_member);
    }
    return unknown_members;
}