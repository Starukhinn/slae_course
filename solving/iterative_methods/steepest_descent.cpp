#include "steepest_descent.h"

std::vector<double> SteepestDescentIteration(const CSRMatrix &matrix_a, const vector<double> &b,
                                             const vector<double> &x0, const double tolerance) {
    vector<double> x = x0;
    vector<double> delta_solve = matrix_a * x - b;
    double alpha;
    while (GiveVectorLength(delta_solve) > tolerance) {
        alpha = delta_solve * delta_solve / (delta_solve * (matrix_a * delta_solve));
        x = x - alpha * delta_solve;
        delta_solve = matrix_a * x - b;
    }
    return x;
}