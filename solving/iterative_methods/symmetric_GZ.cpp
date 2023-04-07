#include "symmetric_GZ.h"

vector<double> MakeFirstIterationOfSymmetricGZ(const CSRMatrix& a_matrix, const vector<double>& x_0,
                                               const vector<double>& b) {
    vector<double> x = x_0;
    for (int number_row = 0; number_row < x.size(); ++number_row) {
        x[number_row] = b[number_row];
        double diag_element;
        for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
             number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
             ++number_non_0_row_element) {
            if (a_matrix.GiveColumnsIndexes()[number_non_0_row_element] == number_row) {
                diag_element = a_matrix.GiveValues()[number_non_0_row_element];
            } else {
                x[number_row] -= a_matrix.GiveValues()[number_non_0_row_element] *
                                 x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
            }
        }
        x[number_row] /= diag_element;
    }

    for (int number_row = x.size() - 1; number_row >= 0; --number_row) {
        x[number_row] = b[number_row];
        double diag_element;
        for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
             number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
             ++number_non_0_row_element) {
            if (a_matrix.GiveColumnsIndexes()[number_non_0_row_element] == number_row) {
                diag_element = a_matrix.GiveValues()[number_non_0_row_element];
            } else {
                x[number_row] -= a_matrix.GiveValues()[number_non_0_row_element] *
                                 x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
            }
        }
        x[number_row] /= diag_element;
    }
    return x;
}

void SwapVectors(vector<double>& vector1, vector<double>& vector2) {
    vector<double> auxiliary_vector = vector2;
    vector2 = vector1;
    vector1 = auxiliary_vector;
}

pair<vector<double>, int> SymmetricGZ(const CSRMatrix& a_matrix, const vector<double>& x_0,
                                      const vector<double>& b, const double& rho,
                                      const double& tolerance) {
    vector<double> y_0 = x_0;
    vector<double> y_1 = MakeFirstIterationOfSymmetricGZ(a_matrix, y_0, b);
    double mu_0 = 1;
    double mu_1 = 1 / rho;
    vector<double> delta_solve = b - a_matrix * y_1;
    size_t number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        vector<double> y_2 = MakeFirstIterationOfSymmetricGZ(a_matrix, y_1, b);
        y_0 = -mu_0 * y_0 + 2 * mu_1 / rho * y_2;
        mu_0 = 2 / rho * mu_1 - mu_0;
        y_0 = y_0 / mu_0;
        SwapVectors(y_0, y_1);
        swap(mu_0, mu_1);
        delta_solve = a_matrix * y_1 - b;
        ++number_iteration;
    }
    return make_pair(y_1, number_iteration);
}