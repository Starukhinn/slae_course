#include "jacobi.h"

#include <fstream>
#include <iomanip>

pair<vector<double>, int> Jacobi(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                 const vector<double> &b, const double &tolerance,
                                 const string &file_path) {
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    vector<double> initial_x;
    int number_iteration = 0;
    std::ofstream outfile;
    outfile.open(file_path, std::ofstream::out | std::ofstream::app);
    while (GiveVectorLength(delta_solve) >= tolerance) {
        initial_x = x;
        for (int number_row = 0; number_row < a_matrix.GiveNumberRows(); ++number_row) {
            double result_column_element = 0;
            for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
                 number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
                 ++number_non_0_row_element) {
                if (number_row == a_matrix.GiveColumnsIndexes()[number_non_0_row_element]) {
                    continue;
                }
                int number_column_row = a_matrix.GiveColumnsIndexes()[number_non_0_row_element];
                result_column_element +=
                    a_matrix.GiveValues()[number_non_0_row_element] * initial_x[number_column_row];
            }
            x[number_row] = (b[number_row] - result_column_element) /
                            a_matrix.GiveElement(number_row, number_row);
        }
        delta_solve = a_matrix * x - b;
        ++number_iteration;
        outfile << log(GiveVectorLength(delta_solve)) << " " << number_iteration << "\n";
    }
    return {x, number_iteration};
}
