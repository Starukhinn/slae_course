#include "fast_descent.h"

pair<vector<double>, int> FastDescent(const CSRMatrix &a_matrix, const vector<double> &x_0,
                                      const vector<double> &b, const double &tolerance){
    vector<double> x = x_0;
    vector<double> delta_solve = a_matrix * x - b;
    int number_iterations = 0;
    while (GiveVectorLength(delta_solve) >= tolerance){
        vector<double> a_matrix_multiply_delta_solve = a_matrix * delta_solve;
        double multiplication_constant =
            delta_solve * delta_solve / (delta_solve * a_matrix_multiply_delta_solve);
        x = x - multiplication_constant * delta_solve;
        delta_solve = a_matrix * x - b;
        ++number_iterations;
    }
    return {x, number_iterations};
}