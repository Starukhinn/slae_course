#include "steepest_descent.h"

pair<vector<double>, int> SteepestDescentIteration(const CSRMatrix &matrix_a, const vector<double> &x0, const vector<double> &b, const double tolerance) {
    vector<double> x = x0;
    vector<double> delta_solve = matrix_a * x - b;
    double alpha;
    int number_iterations = 0;
    while (GiveVectorLength(delta_solve) > tolerance) {
        alpha = delta_solve * delta_solve / (delta_solve * (matrix_a * delta_solve));
        x = x - alpha * delta_solve;
        delta_solve = matrix_a * x - b;
        ++number_iterations;
    }
    return {x, number_iterations};
}