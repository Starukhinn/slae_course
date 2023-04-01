#include "SOR.h"

pair<vector<double>, int> SOR(const CSRMatrix &a_matrix, const vector<double> x_0,
                              const vector<double> b, const double &tolerance,
                              const double &omega) {
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    int number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        for (int number_row = 0; number_row < a_matrix.GiveNumberRows(); ++number_row) {
            double result_column_element = 0;
            double diagonal_element;
            for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
                 number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
                 ++number_non_0_row_element) {
                if (number_row == a_matrix.GiveColumnsIndexes()[number_non_0_row_element]) {
                    diagonal_element = a_matrix.GiveValues()[number_non_0_row_element];
                } else {
                    result_column_element +=
                        a_matrix.GiveValues()[number_non_0_row_element] *
                        x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
                }
            }
            x[number_row] = omega * (b[number_row] - result_column_element) / diagonal_element +
                            (1 - omega) * x[number_row];
        }
        delta_solve = a_matrix * x - b;
        ++number_iteration;
    }
    return {x, number_iteration};
}