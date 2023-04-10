#include "CG_method.h"

pair<vector<double>, int> CG(const CSRMatrix &a_matrix, const vector<double> &x_0, vector<double> b,
                             const double &tolerance) {
    std::ofstream outfile;
    outfile.open("/Users/dmitrystarukhin/slae_course/GTest/KR2/2_task/CG.txt", std::ofstream::out | std::ofstream::app);
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    int number_iterations = 0;
    vector<double> basis_vector = delta_solve;
    outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
    while (GiveVectorLength(delta_solve) >= tolerance) {
        for (int number_row = 0; number_row < x.size(); ++number_row) {
            if (GiveVectorLength(delta_solve) == 0) {
                return {x, number_iterations};
            }
            vector<double> a_matrix_multiply_basis_vector = a_matrix * basis_vector;
            double delta_solve_multiply_basis_vector = basis_vector * delta_solve;
            double multiplication_constant =
                delta_solve_multiply_basis_vector / (basis_vector * a_matrix_multiply_basis_vector);
            x = x - multiplication_constant * basis_vector;
            delta_solve = a_matrix * x - b;
            basis_vector = delta_solve + delta_solve * delta_solve /
                                             delta_solve_multiply_basis_vector * basis_vector;
            ++number_iterations;
            outfile << delta_solve[0] << " " << delta_solve[1] << "\n";
        }
    }
    return {x, number_iterations};
}
