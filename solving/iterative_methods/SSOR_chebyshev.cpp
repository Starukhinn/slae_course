#include "SSOR_chebyshev.h"

vector<double> SSORIterationChebyshev(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                      const vector<double> &b, double omega) {
    vector<double> x = x_0;
    for (int number_row = 0; number_row < x_0.size(); ++number_row) {
        double result_column_element = 0;
        double diagonal_element;
        for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
             number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
             ++number_non_0_row_element) {
            if (number_row == a_matrix.GiveColumnsIndexes()[number_non_0_row_element]) {
                diagonal_element = a_matrix.GiveValues()[number_non_0_row_element];
            } else {
                result_column_element += a_matrix.GiveValues()[number_non_0_row_element] *
                                         x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
            }
        }
        x[number_row] = omega * (b[number_row] - result_column_element) / diagonal_element +
                        (1 - omega) * x[number_row];
    }
    for (int number_row = x.size() - 1; number_row >= 0; --number_row) {
        double result_column_element = 0;
        double diagonal_element;
        for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
             number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
             ++number_non_0_row_element) {
            if (number_row == a_matrix.GiveColumnsIndexes()[number_non_0_row_element]) {
                diagonal_element = a_matrix.GiveValues()[number_non_0_row_element];
            } else {
                result_column_element += a_matrix.GiveValues()[number_non_0_row_element] *
                                         x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
            }
        }
        x[number_row] = omega * (b[number_row] - result_column_element) / diagonal_element +
                        (1 - omega) * x[number_row];
    }
    return x;
}

void SwapVectorsChebyshev(vector<double> &vector1, vector<double> &vector2) {
    vector<double> auxiliary_vector = vector2;
    vector2 = vector1;
    vector1 = auxiliary_vector;
}

pair<vector<double>, int> SSORChebyshev(const CSRMatrix a_matrix, const vector<double> &x_0,
                                        const vector<double> &b, const double &omega,
                                        const double &rho, const double &tolerance) {
    vector<double> y_0 = x_0;
    vector<double> y_1 = SSORIterationChebyshev(a_matrix, y_0, b, omega);
    double mu_0 = 1;
    double mu_1 = 1 / rho;
    vector<double> delta_solve = a_matrix * y_1 - b;
    int number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        vector<double> y_2 = SSORIterationChebyshev(a_matrix, y_1, b, omega);
        y_0 = 2 * mu_1 / rho * y_2 - mu_0 * y_0;
        mu_0 = 2 / rho * mu_1 - mu_0;
        y_0 = y_0 / mu_0;
        SwapVectorsChebyshev(y_0, y_1);
        swap(mu_0, mu_1);
        delta_solve = a_matrix * y_1 - b;
        ++number_iteration;
    }
    return {y_1, number_iteration};
}