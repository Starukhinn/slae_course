#include "GZ.h"
#include <iomanip>
#include <fstream>

vector<float> GZ(const CSRMatrix &a_matrix, const vector<float> &x_0, const vector<float> &b,
         float tolerance) {
    vector<float> x = x_0;
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/solving/iterative_methods/data_graphs/GZ.txt",
                 std::ofstream::out | std::ofstream::app);
    vector<float> delta_solve = a_matrix * x - b;
    int number_iteration = 0;
    while (GiveVectorLength(delta_solve) >= tolerance) {
        outfile << log(GiveVectorLength(delta_solve)) << " ";
        for (int number_row = 0; number_row < a_matrix.GiveNumberRows(); ++number_row) {
            float result_column_element = 0;
            for (int number_non_0_row_element = a_matrix.GiveNumberRowsNon0Elements()[number_row];
                 number_non_0_row_element < a_matrix.GiveNumberRowsNon0Elements()[number_row + 1];
                 ++number_non_0_row_element) {
                if (number_row == a_matrix.GiveColumnsIndexes()[number_non_0_row_element]) {
                    continue;
                }
                result_column_element += a_matrix.GiveValues()[number_non_0_row_element] *
                                         x[a_matrix.GiveColumnsIndexes()[number_non_0_row_element]];
            }
            x[number_row] = (b[number_row] - result_column_element) /
                            a_matrix.GiveElement(number_row, number_row);
        }
        delta_solve = a_matrix * x - b;
        ++number_iteration;
        outfile << number_iteration << " " << number_iteration << '\n';
    }
    outfile.close();
    return x;
}